//
// Created by Matthew McCall on 11/10/22.
//

#include "Oasis/Substitute.hpp"
#include "Oasis/Oasis.hpp"

int main(int argc, const char **argv) {
    auto expr = oa::Multiply::Factory {
        oa::Real::Factory { 4 },
        oa::Exponent::Factory {
                oa::Variable::Factory { "x" },
                oa::Real::Factory { 2 } }
    };

    auto substituted = oa::substitute(expr, "x", oa::Real::Factory { 3 });

    assert(substituted);

    auto [result, error, cause] = substituted->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == 36);
}