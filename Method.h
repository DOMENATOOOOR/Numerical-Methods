#pragma once
#include <cmath>

using Func = double (*)(double);

class Method {
protected:
    Func f;
    double a, b;
    double eps;

    double derivative(double x) const;

public:
    Method(Func f, double a, double b, double eps = 1e-6);
    virtual ~Method() = default;
    virtual double launch() = 0;
};