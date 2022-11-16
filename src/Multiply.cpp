//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Multiply.hpp"
#include "Oasis/Oasis.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    EvaluateReturnType Multiply::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            auto &leftReal = dynamic_cast<Real &>(*leftResult);
            auto &rightReal = dynamic_cast<Real &>(*rightResult);

            return EvaluateReturnType { RealFactory { leftReal.getVal() * rightReal.getVal() } };
        }

        if (leftResult == rightResult) {
            return EvaluateReturnType { ExponentFactory { leftResult->copy(), RealFactory { 2 } } };
        }

        if (rightResult->getType() == Expression::Type::REAL) {// Move coefficients to the left for standard formatting
            return EvaluateReturnType { MultiplyFactory { std::move(rightResult), std::move(leftResult) } };
        }

        return EvaluateReturnType { MultiplyFactory { std::move(leftResult), std::move(rightResult) } };
    }

    Multiply::Multiply(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Multiply::Multiply() : BinaryExpressionNode() { }

}// namespace oa