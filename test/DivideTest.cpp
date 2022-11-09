//
// Created by Andrew Nazareth on 11/9/22.
//

#include "spdlog/spdlog.h"

#include "Oasis/Divide.hpp"
#include "Oasis/Real.hpp"

void testDivide(double a, double b) {

    std::unique_ptr<oa::Divide> divide = oa::Divide::Factory {
        oa::Real::Factory { a },
        oa::Real::Factory { b }
    };

    auto [result, error, cause] = divide->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (a / b));

    spdlog::info("{} / {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testDivide(2, 3);
    testDivide(-1, 1);
    testDivide(9, -8);

    testDivide(3.14, 2.29);
    testDivide(-69, 42);
    testDivide(6.28, -2);
}