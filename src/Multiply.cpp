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

        if (leftResult->getType() == Expression::Type::EXPONENT && rightResult->getType() == Expression::Type::EXPONENT) {
            auto &leftExponent = dynamic_cast<Exponent &>(*leftResult);
            auto &rightExponent = dynamic_cast<Exponent &>(*rightResult);

            if (*leftExponent.getLeft() == *rightExponent.getLeft()) {
                std::unique_ptr<Add> newExponent = AddFactory { leftExponent.getRight()->copy(), rightExponent.getRight()->copy() };
                auto [newExponentAddResult, newExponentAddError, newExponentAddCause] = newExponent->evaluate();

                if (newExponentAddError) {
                    return { {}, newExponentAddError, newExponentAddCause };
                }

                return EvaluateReturnType { ExponentFactory { leftExponent.getLeft()->copy(), newExponentAddResult->copy() } };
            }
        }

        if (rightResult->getType() == Expression::Type::EXPONENT) {
            auto &right = dynamic_cast<Exponent &>(*rightResult);

            if (*right.getLeft() == *leftResult) {

                std::unique_ptr<Add> newExponent = AddFactory { right.getRight()->copy(), RealFactory { 1 } };
                auto [newExponentAddResult, newExponentAddError, newExponentAddCause] = newExponent->evaluate();

                if (newExponentAddError) {
                    return { {}, newExponentAddError, newExponentAddCause };
                }

                return EvaluateReturnType {
                    ExponentFactory { leftResult->copy(), newExponentAddResult->copy() }
                };
            }
        }

        if (leftResult->getType() == Expression::Type::EXPONENT) {
            auto &left = dynamic_cast<Exponent &>(*leftResult);

            if (*left.getLeft() == *rightResult) {

                std::unique_ptr<Add> newExponent = AddFactory { left.getRight()->copy(), RealFactory { 1 } };
                auto [newExponentAddResult, newExponentAddError, newExponentAddCause] = newExponent->evaluate();

                if (newExponentAddError) {
                    return { {}, newExponentAddError, newExponentAddCause };
                }

                return EvaluateReturnType {
                    ExponentFactory { rightResult->copy(), newExponentAddResult->copy() }
                };
            }
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