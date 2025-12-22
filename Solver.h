#pragma once
#include "Method.h"

class Solver {
    Method* method = nullptr;

public:
    void setMethod(Method* m);
    double solve();
};