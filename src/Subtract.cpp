//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Subtract.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    EvaluateReturnType Subtract::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { Real::Factory { leftReal->getVal() - rightReal->getVal() } };
        }

        return EvaluateReturnType { Subtract::Factory { std::move(leftResult), std::move(rightResult) } };
    }

    Subtract::Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }
}// namespace oa