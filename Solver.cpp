#include "Solver.h"

void Solver::setMethod(Method* m) {
    method = m;
}

double Solver::solve() {
    return method->launch();
}
