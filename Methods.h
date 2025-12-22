#pragma once
#include "Method.h"

class BisectionMethod : public Method {
public:
    BisectionMethod(Func f, double a, double b, double eps = 1e-6);
    double launch() override;
};

class ChordMethod : public Method {
public:
    ChordMethod(Func f, double a, double b, double eps = 1e-6);
    double launch() override;
};

class NewtonMethod : public Method {
public:
    NewtonMethod(Func f, double a, double b, double eps = 1e-6);
    double launch() override;
};
