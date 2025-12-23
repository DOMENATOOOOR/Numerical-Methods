#pragma once
#include <memory>
#include "Method.h"

class Solver {
    std::unique_ptr<Method> method;

public:
    void setMethod(std::unique_ptr<Method> m);
    double solve();
};
