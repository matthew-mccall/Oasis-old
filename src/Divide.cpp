//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Divide.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    EvaluateReturnType Divide::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { Real::Factory { leftReal->getVal() / rightReal->getVal() } };
        }

        return EvaluateReturnType { Divide::Factory { std::move(leftResult), std::move(rightResult) } };
    }

    Divide::Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }
    std::unique_ptr<oa::Expression> Divide::copy() const {
        return Divide::Factory();
    }
    Divide::Divide() : BinaryExpressionNode() { }
}// namespace oa