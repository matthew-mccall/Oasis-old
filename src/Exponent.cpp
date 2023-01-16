//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Exponent.hpp"
#include "Oasis/Real.hpp"
#include <cmath>

namespace oa {
    std::unique_ptr<Expression> Exponent::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return RealFactory { pow(leftReal->getVal(), rightReal->getVal()) };
        }

        return ExponentFactory { std::move(leftResult), std::move(rightResult) };
    }

    Exponent::Exponent(std::unique_ptr<Expression> &&base, std::unique_ptr<Expression> &&power) : BinaryExpressionNode(std::move(base), std::move(power)) { }

    Exponent::Exponent() : BinaryExpressionNode() { }

    OA_DEFINE_BINARYEXPRESSION_COPY_FUNCS(Exponent)

}// namespace oa
