//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Divide.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    std::unique_ptr<Expression> Divide::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();

        if (rightResult->getType() == Expression::Type::REAL) {
            auto &denominator = dynamic_cast<Real &>(*rightResult);

            if (denominator == Real { 0 }) {
                throw DivideByZeroException(denominator);
            }
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {

            auto &numerator = dynamic_cast<Real &>(*leftResult);
            auto &denominator = dynamic_cast<Real &>(*rightResult);

            return RealFactory { numerator.getVal() / denominator.getVal() };
        }

        return DivideFactory { std::move(leftResult), std::move(rightResult) };
    }

    Divide::Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Divide::Divide() : BinaryExpressionNode() { }

    DivideByZeroException::DivideByZeroException(const Expression &cause) : Exception(cause, "Cannot divide by zero!") { }
}// namespace oa