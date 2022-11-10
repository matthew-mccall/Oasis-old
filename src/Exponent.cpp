//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Exponent.hpp"
#include "Oasis/Real.hpp"
#include <cmath>

namespace oa {
    EvaluateReturnType Exponent::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { Real::Factory { pow(leftReal->getVal(), rightReal->getVal()) } };
        }

        return EvaluateReturnType { Exponent::Factory { std::move(leftResult), std::move(rightResult) } };
    }

    Exponent::Exponent(std::unique_ptr<Expression> &&base, std::unique_ptr<Expression> &&power) : BinaryExpressionNode(std::move(base), std::move(power)) { }
    std::unique_ptr<oa::Expression> Exponent::copy() {
        return Exponent::Factory { _left->copy(), _right->copy() };
    }
}// namespace oa
