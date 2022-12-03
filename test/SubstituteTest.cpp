//
// Created by Matthew McCall on 11/10/22.
//

#include "Oasis/Substitute.hpp"
#include "Oasis/Oasis.hpp"

int main(int argc, const char **argv) {

    std::unique_ptr<oa::Expression> expr = oa::MultiplyFactory {
        oa::RealFactory { 4 },
        oa::ExponentFactory {
                oa::VariableFactory { "x" },
                oa::RealFactory { 2 } }
    };

    assert(expr);

    auto substituted = oa::substitute(expr, "x", oa::RealFactory { 3 });

    assert(substituted);

    auto result = substituted->evaluate();
    assert(result->getType() == oa::Expression::Type::REAL);

    auto *realResult = dynamic_cast<oa::Real *>(result.get());
    assert(realResult->getVal() == 36);
}