#include <iostream>
#include "Methods.h"
#include "Solver.h"

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a = 1.0;
    double b = 2.0;

    BisectionMethod bisection(f, a, b);
    ChordMethod chord(f, a, b);
    NewtonMethod newton(f, a, b);

    Solver solver;

    solver.setMethod(&bisection);
    std::cout << "Bisection: " << solver.solve() << std::endl;

    solver.setMethod(&chord);
    std::cout << "Chord:     " << solver.solve() << std::endl;

    solver.setMethod(&newton);
    std::cout << "Newton:    " << solver.solve() << std::endl;

    return 0;
}
