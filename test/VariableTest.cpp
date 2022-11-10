//
// Created by Andrew Nazareth on 11/9/22.
//

#include "spdlog/spdlog.h"

#include "Oasis/Add.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"

void testVariable(double a, double b) {

    std::unique_ptr<oa::Add> add = oa::Add::Factory {
        oa::Real::Factory { a },
        oa::Real::Factory { b }
    };

    auto [result, error, cause] = add->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == (a + b));

    spdlog::info("{} + {} = {}", a, b, realResult->getVal());
}

int main(int argc, char **argv) {

    testVariable(2, 3);
    testVariable(-1, 1);
    testVariable(9, -8);

    testVariable(3.14, 2.29);
    testVariable(-69, 42);
    testVariable(6.28, -2);
}