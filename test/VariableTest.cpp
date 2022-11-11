//
// Created by Andrew Nazareth on 11/9/22.
//

#include <cassert>

#include "spdlog/spdlog.h"

#include "Oasis/Oasis.hpp"
#include "Oasis/Add.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Variable.hpp"
#include "Oasis/Substitute.hpp"

void testVariableAdd(double a, double b, std::string var, double val) {

    auto expr = oa::Add::Factory {
        oa::Multiply::Factory { oa::Real::Factory{a}, oa::Variable::Factory{var} },
        oa::Multiply::Factory { oa::Variable::Factory{var}, oa::Real::Factory{b} }
    };

    auto substituted = oa::substitute(expr, var, oa::Real::Factory { val });

    assert(substituted);

    auto [result, error, cause] = substituted->evaluate();
    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    //assert(realResult->getVal() == (a + b));

    spdlog::info("{}{} + {}{} = {}, for {}={}", a, var, b, var, realResult->getVal(), var, val);
}

void testVariableAdd(double a, double b, std::string var) {

    std::unique_ptr<oa::Expression> expr = oa::Add::Factory {
        oa::Multiply::Factory { oa::Real::Factory{a}, oa::Variable::Factory{var} },
        oa::Multiply::Factory { oa::Variable::Factory{var}, oa::Real::Factory{b} }
    };

    auto [result, error, cause] = expr->evaluate();

    std::unique_ptr<oa::Multiply> expr2 = oa::Multiply::Factory{oa::Real::Factory{a+b}, oa::Variable::Factory{var}};

//    assert(result == expr2);

    // auto [result2, error2, cause2] = expr2->evaluate();

    assert(result->getType()==oa::Expression::Type::MULTIPLY);
    oa::Multiply* mul;
    oa::Real* real;
    mul = dynamic_cast<oa::Multiply*>(result.get());
    real = dynamic_cast<oa::Real*>(mul->getLeft().get());

    assert(real->getVal()==a+b);
    // assert()

    /*auto substituted = oa::substitute(expr, var, oa::Real::Factory { 1 });

    assert(substituted);

    //auto [result, error, cause] = substituted->evaluate();
    assert(!error);
    //assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    //assert(realResult->getVal() == (a + b));

    //spdlog::info("{}{} + {}{} = {}{}", a, var, b, var, realResult->getVal(), var);*/
}

int main(int argc, char **argv) {

    testVariableAdd(2, 3, "x", 2);
    testVariableAdd(-1, 1, "y", 5);
    testVariableAdd(9, -8, "z", 3);

    testVariableAdd(3.14, 2.29, "x_1", 4);
    testVariableAdd(-69, 42, "x_2", 9);
    testVariableAdd(6.28, -2, "x_3", 0);

    testVariableAdd(2.3, 7.7, "x");
    testVariableAdd(3.1, -2.514, "z");
}