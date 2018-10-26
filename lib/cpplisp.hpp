//
// Created by Chi-Chun, Chen on 2018/10/26.
//

#ifndef LISP_CPPLISP_HPP
#define LISP_CPPLISP_HPP

#include <utility>
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <sstream>
#include <memory>
#include <stack>
#include <cstdlib>
#include <cassert>

namespace chichun {
    class CPPLisp {
    public:
        int evaluate(std::string expression) {
            level = 0;
            return eval(std::move(expression));
        }

    private:
        std::unordered_map<std::string, int> varTab;

        unsigned int level;

        int binOp(const std::string &expression, int startPos, const std::function<int(int, int)> &op);

        // expression: (add e1 e2)
        int add(const std::string &expression);

        // expression: (mult e1 e2)
        int mult(const std::string &expression);

        // return a string with same number of left paren and right paren
        std::string getExprOrVar(const std::string &expression);

        // expression: (let v1 e1 ... vn en expr)
        int let(const std::string &expression, std::vector<std::string> &gc);

        std::string getLeveledVar(std::string s) {
            return s + "_" + std::to_string(level);
        }

        std::string getLeveledVar(std::string s, int l) {
            return s + "_" + std::to_string(l);
        }

        int eval(std::string expression);
    };
}


#endif //LISP_CPPLISP_HPP
