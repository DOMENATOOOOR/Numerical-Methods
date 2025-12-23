#pragma once
#include <cmath>
#include <stdexcept>

using Func = double (*)(double);

class Method {
protected:
    Func f;
    double a, b;
    double eps;
    static constexpr int MAX_ITER = 1000;

    double derivative(double x) const;

public:
    Method(Func f, double a, double b, double eps = 1e-6);
    virtual ~Method() = default;
    virtual double launch() = 0;
};
