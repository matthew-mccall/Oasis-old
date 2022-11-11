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
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { Real::Factory { leftReal->getVal() + rightReal->getVal() } };
        }

        else if (leftResult->getType() == Expression::Type::MULTIPLY && rightResult->getType() == Expression::Type::MULTIPLY) {
            Multiply *left, *right;
            left = dynamic_cast<Multiply *>(leftResult.get());
            right = dynamic_cast<Multiply *>(rightResult.get());

            Real *leftReal, *rightReal;
            Variable *leftVar, *rightVar;        //if real*var
            Variable *leftLeftVar, *rightLeftVar;// if var*var
            if (left->getLeft()->getType() == Expression::Type::REAL) {
                leftReal = dynamic_cast<Real *>(left->getLeft().get());
            } else {
                exit(-1);//error -1 for invalid expression, will add var*var later, maybe
            }
            if (right->getLeft()->getType() == Expression::Type::REAL) {
                rightReal = dynamic_cast<Real *>(right->getLeft().get());
            } else {
                exit(-1);
            }
            if (left->getRight()->getType() == Expression::Type::VARIABLE) {
                leftVar = dynamic_cast<Variable *>(left->getRight().get());
            } else {
                exit(-1);
            }
            if (right->getRight()->getType() == Expression::Type::VARIABLE) {
                rightVar = dynamic_cast<Variable *>(right->getRight().get());
            } else {
                exit(-1);
            }
            //check to make sure that the variables are the same
            if (leftVar->getRep() == rightVar->getRep()) {
                return EvaluateReturnType { Multiply::Factory { Real::Factory { leftReal->getVal() + rightReal->getVal() }, Variable::Factory { leftVar->getRep() } } };
            }
        }

        else if (leftResult->getType() == Expression::Type::MULTIPLY && rightResult->getType() == Expression::Type::REAL) {
            Real *rightReal;
            Multiply *leftExpr;
            Variable *leftVar;
            Real *leftReal;

            leftExpr = dynamic_cast<Multiply *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());
            leftVar = dynamic_cast<Variable *>(leftExpr->getRight().get());
            leftReal = dynamic_cast<Real *>(leftExpr->getLeft().get());

            return EvaluateReturnType { Add::Factory { Multiply::Factory { Real::Factory { leftReal->getVal() }, Variable::Factory { leftVar->getRep() } }, Real::Factory { rightReal->getVal() } } };
        }

        return EvaluateReturnType { Add::Factory { std::move(leftResult), std::move(rightResult) } };
    }

    Add::Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }
    std::unique_ptr<oa::Expression> Add::copy() const {
        return Add::Factory();
    }
    Add::Add() : BinaryExpressionNode() { }
}// namespace oa