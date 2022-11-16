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
            Real *leftReal, *rightReal;

            leftReal = dynamic_cast<Real *>(leftResult.get());
            rightReal = dynamic_cast<Real *>(rightResult.get());

            return EvaluateReturnType { RealFactory { leftReal->getVal() * rightReal->getVal() } };
        } else if (leftResult->getType() == Expression::Type::REAL && rightResult->getType() == Expression::Type::VARIABLE) {
            Real *left;
            Variable *right;
            left = dynamic_cast<Real *>(leftResult.get());
            right = dynamic_cast<Variable *>(rightResult.get());
            return EvaluateReturnType { MultiplyFactory { RealFactory { left->getVal() }, VariableFactory { right->getRep() } } };
        } else if (leftResult->getType() == Expression::Type::VARIABLE && rightResult->getType() == Expression::Type::REAL) {
            Real *left;
            Variable *right;
            left = dynamic_cast<Real *>(rightResult.get());    //real val
            right = dynamic_cast<Variable *>(leftResult.get());//var val
            return EvaluateReturnType { MultiplyFactory { RealFactory { left->getVal() }, VariableFactory { right->getRep() } } };
        }

        return EvaluateReturnType { MultiplyFactory { std::move(leftResult), std::move(rightResult) } };
    }

    Multiply::Multiply(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Multiply::Multiply() : BinaryExpressionNode() { }

}// namespace oa