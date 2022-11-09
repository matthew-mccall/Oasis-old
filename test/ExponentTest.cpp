//
// Created by Andrew Nazareth on 11/9/22.
//
#include "spdlog/spdlog.h"

#include "Oasis/Exponent.hpp"
#include "Oasis/Real.hpp"

void testExponent(double a, double b) {

    std::unique_ptr<oa::Exponent> exponent = oa::Exponent::Factory {
        oa::Real::Factory { a },
        oa::Real::Factory { b }
    };

    auto [result, error, cause] = exponent->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (pow(a , b)));

    spdlog::info("{} ^ {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testExponent(2, 3);
    testExponent(-1, 1);
    testExponent(9, -8);

    testExponent(3.14, 2.29);
    testExponent(-69, 42);
    testExponent(6.28, -2);
}