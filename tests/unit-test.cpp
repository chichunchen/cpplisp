#include "cpplisp.hpp"

using namespace std;

void unit_test() {
    chichun::CPPLisp lisp;
    assert(lisp.evaluate("(add 1 2)") == 3);
    assert(lisp.evaluate("(mult 3 (add 2 3))") == 15);
    assert(lisp.evaluate("(let x 2 (mult x 5))") == 10);
    assert(lisp.evaluate("(let x 3 y 4 (add x y))") == 7);
    assert(lisp.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") == 14);
    assert(lisp.evaluate("(let x 3 x 2 x)") == 2);
    assert(lisp.evaluate("(let x 1 y 2 x (add x y) (add x y))") == 5);
    assert(lisp.evaluate("(let a1 3 b2 (add a1 1) b2)") == 4);
    assert(lisp.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") == 6);
    assert(lisp.evaluate("(let var 78 b 77 (let c 33 (add c (mult var 66))))") == 5181);
    assert(lisp.evaluate(
            "(let x0 -1 x1 3 x2 3 x3 2 x4 -4 x5 4 x6 -2 x7 -4 x8 -4 x9 -1 (mult (mult x9 x0) (mult (let x0 1 x4 -1 x8 2 (add -10 -8)) (add (add (add (mult (mult (mult (mult -5 (mult 1 1)) -10) -6) (add x5 (add x6 (add x9 (mult 1 1))))) (let x0 -3 x7 -2 (mult (add (mult (mult 1 1) -2) x0) (let x0 -5 x9 0 (add (mult 1 1) -10))))) (mult (add (let x0 -1 x8 3 (mult (mult (mult 1 1) (mult 1 1)) x7)) (mult (mult (mult (mult 1 1) (mult 1 1)) -5) (add -6 (mult (mult 1 1) x0)))) -7)) -7))))") ==
           14022);
}

int main() {
    unit_test();
    return 0;
}