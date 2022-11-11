//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Add.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    EvaluateReturnType Add::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { Real::Factory { leftReal->getVal() + rightReal->getVal() } };
        }

        return EvaluateReturnType { Add::Factory { std::move(leftResult), std::move(rightResult) } };
    }

    Add::Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }
    std::unique_ptr<oa::Expression> Add::copy() const {
        return Add::Factory();
    }
    Add::Add() : BinaryExpressionNode() { }
}// namespace oa