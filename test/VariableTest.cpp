//
// Created by Andrew Nazareth on 11/9/22.
//

#include <cassert>

#include "spdlog/spdlog.h"

#include "Oasis/Add.hpp"
#include "Oasis/Oasis.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Substitute.hpp"
#include "Oasis/Variable.hpp"

void testVariableAdd(double leftCoefficient, double rightCoefficient, const std::unique_ptr<oa::Expression> &commonExpression) {
    std::unique_ptr<oa::Expression> expected = oa::MultiplyFactory {
        oa::RealFactory { leftCoefficient + rightCoefficient },
        commonExpression->copy()
    };

    std::unique_ptr<oa::Expression> add = oa::AddFactory {
        oa::MultiplyFactory {
                oa::RealFactory { leftCoefficient },
                commonExpression->copy() },
        oa::MultiplyFactory {
                oa::RealFactory { rightCoefficient },
                commonExpression->copy() }
    };

    auto [result, error, cause] = add->evaluate();

    assert(!error);
    assert(*result == *expected);
}

int main(int argc, char **argv) {
    testVariableAdd(2, 3, oa::VariableFactory { "x" });
    testVariableAdd(4, 5,
                    oa::ExponentFactory {
                            oa::VariableFactory { "x" },
                            oa::RealFactory { 2 } });
}