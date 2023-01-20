//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Add.hpp"
#include "Oasis/Oasis.hpp"


namespace oa {
    std::unique_ptr<Expression> Add::evaluate() const {
        auto [leftResult, rightResult] = evaluateOperands();
        std::unique_ptr<Add> newAdd = AddFactory { leftResult->copy(), rightResult->copy() };

        if (*leftResult == *rightResult) {
            return MultiplyFactory {
                RealFactory { 2 },
                leftResult->copy()
            };
        }

        if (newAdd->structurallyEquals(Add {
                    RealFactory {},
                    RealFactory {} })) {
            auto &leftReal = dynamic_cast<Real &>(*leftResult);
            auto &rightReal = dynamic_cast<Real &>(*rightResult);

            return RealFactory { leftReal.getVal() + rightReal.getVal() };
        }

        if (newAdd->structurallyEquals(Add {
                    BlankFactory {},
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} } })) {
            auto &rightMultiply = dynamic_cast<Multiply &>(*rightResult);
            auto &rightMultiplyCoefficient = dynamic_cast<Real &>(*rightMultiply.getLeft());

            if (*rightMultiply.getRight() == *leftResult) {
                return MultiplyFactory {
                    RealFactory { rightMultiplyCoefficient.getVal() + 1 },
                    leftResult->copy()
                };
            }
        }

        if (newAdd->structurallyEquals(Add {
                    MultiplyFactory {
                            RealFactory {},
                            BlankFactory {} },
                    BlankFactory {} })) {
            auto &leftMultiply = dynamic_cast<Multiply &>(*leftResult);
            auto &leftMultiplyCoefficient = dynamic_cast<Real &>(*leftMultiply.getLeft());

            if (*leftMultiply.getRight() == *rightResult) {
                return MultiplyFactory {
                    RealFactory { leftMultiplyCoefficient.getVal() + 1 },
                    rightResult->copy()
                };
            }
        }

        if (newAdd->structurallyEquals(Add {
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
                    RealFactory { leftMultiplyCoefficient.getVal() + rightMultiplyCoefficient.getVal() },
                    leftMultiply.getRight()->copy()
                };
            }
        }

        return AddFactory { std::move(leftResult), std::move(rightResult) };
    }

    Add::Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : BinaryExpressionNode(std::move(left), std::move(right)) { }

    Add::Add() : BinaryExpressionNode() { }

    OA_DEFINE_BINARYEXPRESSION_COPY_FUNCS(Add)
}// namespace oa