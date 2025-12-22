#include "Methods.h"
#include <cmath>

BisectionMethod::BisectionMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double BisectionMethod::launch() {
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


ChordMethod::ChordMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double ChordMethod::launch() {
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


NewtonMethod::NewtonMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double NewtonMethod::launch() {
    double x = (a + b) / 2;

    while (std::abs(f(x)) > eps) {
        x -= f(x) / derivative(x);
    }
    return x;
}
