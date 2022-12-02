//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_SUBTRACT_HPP
#define OASIS_SUBTRACT_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    OA_DECLARE_FACTORY(SubtractFactory, Subtract)

    /**
     * The Add class subtracts two expressions
     */
    class Subtract final : public BinaryExpressionNode<SubtractFactory> {
    public:
        Subtract();
        Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        OA_EXPRESSION_TYPE(SUBTRACT)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_ARITHMETIC | EXPRESSION_CATEGORY_BINARY_OPERANDS)
    };

}// namespace oa

#endif//OASIS_SUBTRACT_HPP
