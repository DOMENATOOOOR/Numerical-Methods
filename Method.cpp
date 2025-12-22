#include "Method.h"

Method::Method(Func f, double a, double b, double eps)
    : f(f), a(a), b(b), eps(eps) {}

double Method::derivative(double x) const {
    const double h = 1e-8;
    return (f(x + h) - f(x - h)) / (2 * h);
}
