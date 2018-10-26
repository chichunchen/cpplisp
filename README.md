# cpplisp
Implement basic-version of lisp in cpp.
 It support basic garbage collection, shallow scoping, and a few of operators such as `add`, `mult`, and `let`.

## Prerequisites
- CMake
- C++11/14

## Installation
```bash
mkdir build
cd build
cmake ..
make
```

## Example
```lisp
(let x0 -1 x1 3 x2 3 x3 2 x4 -4 x5 4 x6 -2 x7 -4 x8 -4 x9 -1 (mult (mult x9 x0) (mult (let x0 1 x4 -1 x8 2 (add -10 -8)) (add (add (add (mult (mult (mult (mult -5 (mult 1 1)) -10) -6) (add x5 (add x6 (add x9 (mult 1 1))))) (let x0 -3 x7 -2 (mult (add (mult (mult 1 1) -2) x0) (let x0 -5 x9 0 (add (mult 1 1) -10))))) (mult (add (let x0 -1 x8 3 (mult (mult (mult 1 1) (mult 1 1)) x7)) (mult (mult (mult (mult 1 1) (mult 1 1)) -5) (add -6 (mult (mult 1 1) x0)))) -7)) -7)))))
```