//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Subtract.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    std::unique_ptr<Expression> Subtract::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();

        if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::REAL) {

            auto &leftReal = dynamic_cast<Real &>(*leftResult);
            auto &rightReal = dynamic_cast<Real &>(*rightResult);

            return RealFactory { leftReal.getVal() - rightReal.getVal() };
        }

        if (*leftResult == *rightResult) {
            return RealFactory { 0 };
        }

        if (rightResult->getType() == Expression::Type::MULTIPLY) {
            auto &right = dynamic_cast<Multiply &>(*rightResult);

            if ((right.getLeft()->getType() == Expression::Type::REAL) && (*leftResult == *right.getRight())) {
                auto &rightCoefficient = dynamic_cast<Real &>(*right.getLeft());

                return MultiplyFactory {
                    RealFactory { rightCoefficient.getVal() - 1 },
                    leftResult->copy()
                };
            }
        }

        if (leftResult->getType() == Expression::Type::MULTIPLY) {
            auto &left = dynamic_cast<Multiply &>(*leftResult);

            if ((left.getLeft()->getType() == Expression::Type::REAL) && (*rightResult == *left.getRight())) {
                auto &leftCoefficient = dynamic_cast<Real &>(*left.getLeft());

                return MultiplyFactory {
                    RealFactory { leftCoefficient.getVal() - 1 },
                    rightResult->copy()
                };
            }
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

                return MultiplyFactory {
                    RealFactory { (leftCoefficient.getVal() - rightCoefficient.getVal()) },
                    left.getRight()->copy()
                };
            }
        }

        return SubtractFactory { std::move(leftResult), std::move(rightResult) };
    }

    Subtract::Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Subtract::Subtract() : BinaryExpressionNode() { }

}// namespace oa