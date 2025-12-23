#include "Methods.h"


BisectionMethod::BisectionMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double BisectionMethod::launch() {
    double left = a;
    double right = b;

    for (int i = 0; i < MAX_ITER; ++i) {
        double mid = (left + right) / 2.0;

        if (std::abs(f(mid)) < eps)
            return mid;

        if (f(left) * f(mid) < 0)
            right = mid;
        else
            left = mid;
    }

    throw std::runtime_error("Bisection method MAX_ITER");
}


ChordMethod::ChordMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double ChordMethod::launch() {
    double x0 = a;
    double x1 = b;

    for (int i = 0; i < MAX_ITER; ++i) {
        double f0 = f(x0);
        double f1 = f(x1);

        if (std::abs(f1 - f0) < 1e-12)
            throw std::runtime_error("Chord method: division by zero");

        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        if (std::abs(x2 - x1) < eps)
            return x2;

        x0 = x1;
        x1 = x2;
    }

    throw std::runtime_error("Chord method MAX_ITER");
}



NewtonMethod::NewtonMethod(Func f, double a, double b, double eps)
    : Method(f, a, b, eps) {}

double NewtonMethod::launch() {
    double x = (a + b) / 2.0;

    for (int i = 0; i < MAX_ITER; ++i) {
        double fx = f(x);
        if (std::abs(fx) < eps)
            return x;

        double d = derivative(x);
        if (std::abs(d) < 1e-12)
            throw std::runtime_error("Newton method: derivative is zero");

        x -= fx / d;
    }

    throw std::runtime_error("Newton method MAX_ITER");
}
