//
// Created by Andrew Nazareth on 11/9/22.
//

#include <cassert>

#include "spdlog/spdlog.h"

#include "Oasis/Multiply.hpp"
#include "Oasis/Real.hpp"

void testMultiply(double a, double b) {

    std::unique_ptr<oa::Multiply> multiply = oa::MultiplyFactory {
        oa::RealFactory { a },
        oa::RealFactory { b }
    };

    auto result = multiply->evaluate();
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (a * b));

    spdlog::info("{} * {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testMultiply(2, 3);
    testMultiply(-1, 1);
    testMultiply(9, -8);

    testMultiply(3.14, 2.29);
    testMultiply(-69, 42);
    testMultiply(6.28, -2);
}