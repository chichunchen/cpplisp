//
// Created by Chi-Chun, Chen on 2018/10/26.
//

#include "cpplisp.hpp"

namespace chichun {

    int CPPLisp::binOp(const std::string &expression, int startPos, const std::function<int(int, int)> &op) {
        std::string expr = expression.substr(startPos + 1, expression.length() - startPos - 2);
        std::string e1 = getExprOrVar(expr);
        std::string e2 = expr.substr(e1.length() + 1);
        int i1 = eval(e1);
        int i2 = eval(e2);
        return op(i1, i2);
    }

    int CPPLisp::add(const std::string &expression) {
        return binOp(expression, 4, [](int a, int b) { return a + b; });
    }

    int CPPLisp::mult(const std::string &expression) {
        return binOp(expression, 5, [](int a, int b) { return a * b; });
    }

    std::string CPPLisp::getExprOrVar(const std::string &expression) {
        if (expression[0] != '(') {
            size_t spacePos = expression.find(' ');
            return expression.substr(0, spacePos);
        } else {
            std::stack<char> stk;
            int paren = 1;
            size_t pos = 1;
            for (; paren != 0 && pos < expression.length(); pos++) {
                if (expression[pos] == '(') {
                    paren++;
                } else if (expression[pos] == ')') {
                    paren--;
                }
            }
            return expression.substr(0, pos);
        }
    }

    int CPPLisp::let(const std::string &expression, std::vector<std::string> &gc) {
        std::string expr = expression.substr(5, expression.length() - 6);
        // parse v1 e1
        size_t findSpace = expr.find(' ');
        std::string v1 = expr.substr(0, findSpace) + "_" + std::to_string(level);
        gc.push_back(v1);
        std::string e1 = getExprOrVar(expr.substr(findSpace + 1));
        varTab[v1] = eval(e1);
        expr = expr.substr(findSpace + 2 + e1.length());
        std::string v;
        while (!expr.empty()) {
            v = getExprOrVar(expr);
            if (v.length() == expr.length()) {
                return eval(v);
            } else {
                std::string e = getExprOrVar(expr.substr(v.length() + 1));
                std::string v_l = getLeveledVar(v);
                varTab[v_l] = eval(e);
                gc.push_back(v_l);
                expr = expr.substr(v.length() + 1 + e.length() + 1);
            }
        }
        assert(false);
        return eval(v); // shouldn't reach here
    }

    int CPPLisp::eval(std::string expression) {
        if (expression.find("(let") == 0) {
            std::vector<std::string> gc;
            level++;
            int r = let(expression, gc);
            for (const std::string &var : gc) {
                varTab.erase(var);
            }
            level--;
            return r;
        } else if (expression.find("(add") == 0) {
            return add(expression);
        } else if (expression.find("(mult") == 0) {
            return mult(expression);
        } else {
            for (int i = level; i >= 0; i--) {
                std::string v = getLeveledVar(expression, i);
                if (varTab.find(v) != varTab.end()) {
                    return varTab[v];
                }
            }
            return stoi(expression);    // if not found var then return int
        }
    }
}
