//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Divide.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    std::unique_ptr<Expression> Divide::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return RealFactory { leftReal->getVal() / rightReal->getVal() };
        }

        return DivideFactory { std::move(leftResult), std::move(rightResult) };
    }

    Divide::Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Divide::Divide() : BinaryExpressionNode() { }
}// namespace oa