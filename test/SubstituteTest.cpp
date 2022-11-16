//
// Created by Matthew McCall on 11/10/22.
//

#include "Oasis/Substitute.hpp"
#include "Oasis/Oasis.hpp"

int main(int argc, const char **argv) {
    auto expr = oa::MultiplyFactory {
        oa::RealFactory { 4 },
        oa::ExponentFactory {
                oa::VariableFactory { "x" },
                oa::RealFactory { 2 } }
    };

    auto substituted = oa::substitute(expr, "x", oa::RealFactory { 3 });

    assert(substituted);

    auto [result, error, cause] = substituted->evaluate();

    assert(!error);
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == 36);
}