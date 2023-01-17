//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Subtract.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Real.hpp"

namespace oa {
    std::unique_ptr<Expression> Subtract::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();

        if (*leftResult == *rightResult) {
            return RealFactory { 0 };
        }

        if (this->structurallyEquals(Subtract {
                    RealFactory {},
                    RealFactory {} })) {
            auto &leftReal = dynamic_cast<Real &>(*leftResult);
            auto &rightReal = dynamic_cast<Real &>(*rightResult);

            return RealFactory { leftReal.getVal() - rightReal.getVal() };
        }

        if (this->structurallyEquals(Subtract {
                    BlankFactory {},
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} } })) {
            auto &rightMultiply = dynamic_cast<Multiply &>(*rightResult);
            auto &rightMultiplyCoefficient = dynamic_cast<Real &>(*rightMultiply.getLeft());

            if (*rightMultiply.getRight() == *leftResult) {
                return MultiplyFactory {
                    RealFactory { rightMultiplyCoefficient.getVal() - 1 },
                    leftResult->copy()
                };
            }
        }

        if (this->structurallyEquals(Subtract {
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} },
                    BlankFactory {} })) {
            auto &leftMultiply = dynamic_cast<Multiply &>(*leftResult);
            auto &leftMultiplyCoefficient = dynamic_cast<Real &>(*leftMultiply.getLeft());

            if (*leftMultiply.getRight() == *rightResult) {
                return MultiplyFactory {
                    RealFactory { leftMultiplyCoefficient.getVal() - 1 },
                    rightResult->copy()
                };
            }
        }

        if (this->structurallyEquals(Subtract {
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} },
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} } })) {
            auto &leftMultiply = dynamic_cast<Multiply &>(*leftResult);
            auto &leftMultiplyCoefficient = dynamic_cast<Real &>(*leftMultiply.getLeft());
            auto &rightMultiply = dynamic_cast<Multiply &>(*rightResult);
            auto &rightMultiplyCoefficient = dynamic_cast<Real &>(*rightMultiply.getLeft());

            if (*leftMultiply.getRight() == *rightMultiply.getRight()) {
                return MultiplyFactory {
                    RealFactory { leftMultiplyCoefficient.getVal() - rightMultiplyCoefficient.getVal() },
                    leftMultiply.getRight()->copy()
                };
            }
        }

        return SubtractFactory { std::move(leftResult), std::move(rightResult) };
    }

    Subtract::Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Subtract::Subtract() : BinaryExpressionNode() { }

    OA_DEFINE_BINARYEXPRESSION_COPY_FUNCS(Subtract)

}// namespace oa