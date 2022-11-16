//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Oasis.hpp"

namespace oa {
    EvaluateReturnType Add::evaluate() const {
        auto [leftResult, rightResult, error, cause] = evaluateOperands();

        if (error) {
            return { nullptr, error, cause };
        }

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {

            auto &leftReal = dynamic_cast<Real &>(*leftResult);
            auto &rightReal = dynamic_cast<Real &>(*rightResult);

            return EvaluateReturnType { RealFactory { leftReal.getVal() + rightReal.getVal() } };
        }

        if (leftResult->getType() == Expression::Type::MULTIPLY && rightResult->getType() == Expression::Type::MULTIPLY) {
            auto &left = dynamic_cast<Multiply &>(*leftResult);
            auto &right = dynamic_cast<Multiply &>(*rightResult);

            if (
                    (left.getLeft()->getType() == Expression::Type::REAL) &&
                    (right.getLeft()->getType() == Expression::Type::REAL) &&
                    (*left.getRight() == *right.getRight())) {

                auto &leftCoefficient = dynamic_cast<Real &>(*left.getLeft());
                auto &rightCoefficient = dynamic_cast<Real &>(*right.getLeft());

                return EvaluateReturnType {
                    MultiplyFactory {
                            RealFactory { (leftCoefficient.getVal() + rightCoefficient.getVal()) },
                            left.getRight()->copy() }
                };
            }
        }

        return EvaluateReturnType { AddFactory { std::move(leftResult), std::move(rightResult) } };
    }

    Add::Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Add::Add() : BinaryExpressionNode() { }
}// namespace oa