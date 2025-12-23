#include <gtest/gtest.h>
#include "Methods.h"
#include "Solver.h"

constexpr double EPS = 1e-6;

double f(double x) {
    return x * x - 2;
}

TEST(BisectionMethodTest, FindsSqrt2) {
    BisectionMethod method(f, 1.0, 2.0, EPS);
    EXPECT_NEAR(method.launch(), std::sqrt(2.0), EPS);
}

TEST(ChordMethodTest, FindsSqrt2) {
    ChordMethod method(f, 1.0, 2.0, EPS);
    EXPECT_NEAR(method.launch(), std::sqrt(2.0), EPS);
}

TEST(NewtonMethodTest, FindsSqrt2) {
    NewtonMethod method(f, 1.0, 2.0, EPS);
    EXPECT_NEAR(method.launch(), std::sqrt(2.0), EPS);
}

TEST(StrategyTest, MethodsAreInterchangeable) {
    Solver solver;

    solver.setMethod(std::make_unique<BisectionMethod>(f, 1.0, 2.0, EPS));
    double r1 = solver.solve();

    solver.setMethod(std::make_unique<ChordMethod>(f, 1.0, 2.0, EPS));
    double r2 = solver.solve();

    solver.setMethod(std::make_unique<NewtonMethod>(f, 1.0, 2.0, EPS));
    double r3 = solver.solve();

    EXPECT_NEAR(r1, r2, EPS);
    EXPECT_NEAR(r2, r3, EPS);
}

double f2(double x) {
    return x * x * x - x - 2;
}

TEST(ExtraTest, CubicEquation) {
    NewtonMethod method(f2, 1.0, 2.0, EPS);
    EXPECT_NEAR(method.launch(), 1.52138, 1e-5);
}

double no_root(double x) {
    return x * x + 1;
}

TEST(IterationLimitTest, NewtonMethodThrowsAfterMaxIterations) {
    NewtonMethod method(no_root, -1.0, 1.0, EPS);

    EXPECT_THROW(
        method.launch(),
        std::runtime_error
    );
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
