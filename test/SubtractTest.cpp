//
// Created by Andrew Nazareth on 11/9/22.
//

#include <cassert>

#include "spdlog/spdlog.h"

#include "Oasis/Subtract.hpp"
#include "Oasis/Real.hpp"

void testSubtract(double a, double b) {

    std::unique_ptr<oa::Subtract> subtract = oa::Subtract::Factory {
        oa::Real::Factory { a },
        oa::Real::Factory { b }
    };

    auto [result, error, cause] = subtract->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (a - b));

    spdlog::info("{} - {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testSubtract(2, 3);
    testSubtract(-1, 1);
    testSubtract(9, -8);

    testSubtract(3.14, 2.29);
    testSubtract(-69, 42);
    testSubtract(6.28, -2);
}