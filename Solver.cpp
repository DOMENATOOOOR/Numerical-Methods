#include "Solver.h"


void Solver::setMethod(std::unique_ptr<Method> m) {
    method = std::move(m);
}

double Solver::solve() {
    if (!method)
        throw std::runtime_error("Solver: method not set");
    return method->launch();
}
