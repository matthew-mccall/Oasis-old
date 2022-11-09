//
// Created by Matthew McCall on 11/8/22.
//

#include "spdlog/spdlog.h"

#include "Oasis/Add.hpp"
#include "Oasis/Real.hpp"

void testAdd(double a, double b) {
    auto add = oa::Add::Factory(oa::Real::Factory(a), oa::Real::Factory(b));
    auto [result, error, cause] = add->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (a + b));

    spdlog::info("{} + {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testAdd(2, 3);
    testAdd(-1, 1);
    testAdd(9, -8);

    testAdd(3.14, 2.29);
    testAdd(-69, 42);
    testAdd(6.28, -2);
}