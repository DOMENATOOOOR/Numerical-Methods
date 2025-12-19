#pragma once
#include <iostream>
#include <cmath>
using Func = double (*)(double);

class Method {
protected:
    Func f;
    Func df;

    double a, b;
    double eps;

public:
    Method(Func f, Func df, double a, double b, double eps = 1e-6)
        : f(f), df(df), a(a), b(b), eps(eps) {}

    virtual ~Method() = default;
    virtual double launch() = 0;
};


class BisectionMethod : public Method {
public:
    BisectionMethod(Func f, double a, double b, double eps = 1e-6)
        : Method(f, nullptr, a, b, eps) {}

    double launch() override {
        double left = a, right = b, mid;

        while ((right - left) / 2 > eps) {
            mid = (left + right) / 2;

            if (f(mid) == 0.0)
                return mid;

            if (f(left) * f(mid) < 0)
                right = mid;
            else
                left = mid;
        }

        return (left + right) / 2;
    }
};


class ChordMethod : public Method {
public:
    ChordMethod(Func f, double a, double b, double eps = 1e-6)
        : Method(f, nullptr, a, b, eps) {}

    double launch() override {
        double x0 = a;
        double x1 = b;
        double x2;

        while (std::abs(x1 - x0) > eps) {
            x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
            x0 = x1;
            x1 = x2;
        }

        return x1;
    }
};

class NewtonMethod : public Method {
public:
    NewtonMethod(Func f, Func df, double a, double b, double eps = 1e-6)
        : Method(f, df, a, b, eps) {}

    double launch() override {
        double x = (a + b) / 2;

        while (std::abs(f(x)) > eps) {
            x = x - f(x) / df(x);
        }

        return x;
    }
};

class Solver {
    Method* method;

public:
    void setMethod(Method* m) {
        method = m;
    }

    double solve() {
        return method->launch();
    }
};
