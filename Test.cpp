#include <gtest/gtest.h>
#include <cmath>
#include "Methods.h"
#include "Solver.h"

constexpr double EPS = 1e-6;

double f(double x) {
    return x * x - 2;
}

TEST(BisectionMethodTest, FindsSqrt2) {
    BisectionMethod method(f, 1.0, 2.0, EPS);
    double root = method.launch();

    EXPECT_NEAR(root, std::sqrt(2.0), EPS);
}

TEST(ChordMethodTest, FindsSqrt2) {
    ChordMethod method(f, 1.0, 2.0, EPS);
    double root = method.launch();

    EXPECT_NEAR(root, std::sqrt(2.0), EPS);
}

TEST(NewtonMethodTest, FindsSqrt2) {
    NewtonMethod method(f, 1.0, 2.0, EPS);
    double root = method.launch();

    EXPECT_NEAR(root, std::sqrt(2.0), EPS);
}

TEST(StrategyTest, MethodsAreInterchangeable) {
    Solver solver;

    BisectionMethod bisection(f, 1.0, 2.0, EPS);
    ChordMethod chord(f, 1.0, 2.0, EPS);
    NewtonMethod newton(f, 1.0, 2.0, EPS);

    solver.setMethod(&bisection);
    double r1 = solver.solve();

    solver.setMethod(&chord);
    double r2 = solver.solve();

    solver.setMethod(&newton);
    double r3 = solver.solve();

    EXPECT_NEAR(r1, r2, EPS);
    EXPECT_NEAR(r2, r3, EPS);
}

TEST(ArchitectureTest, UsesBaseClassPointer) {
    Method* method;

    BisectionMethod bisection(f, 1.0, 2.0);
    method = &bisection;

    double root = method->launch();

    EXPECT_NEAR(root, std::sqrt(2.0), EPS);
}

double f2(double x) {
    return x * x * x - x - 2;
}

TEST(ExtraTest, CubicEquation) {
    NewtonMethod method(f2, 1.0, 2.0, EPS);
    double root = method.launch();

    EXPECT_NEAR(root, 1.52138, 1e-5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
