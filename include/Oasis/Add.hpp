//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_ADD_HPP
#define OASIS_ADD_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The Add class adds two expressions
     */
    class Add final : public BinaryExpressionNode {
    public:
        Add();
        /**
         * Creates a new Add expression from two operands
         * @param left The left operand
         * @param right The right operand
         */
        Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        /**
         * Evaluates the operands and adds them if they are Real operands
         *
         * @throws BlankException if either operand is blank
         * @return The simplified expression.
         */
        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        OA_EXPRESSION_TYPE(ADD)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_ARITHMETIC | EXPRESSION_CATEGORY_BINARY_OPERANDS)

        OA_OVERRIDE_COPY_FUNCS
    };

    OA_DECLARE_FACTORY(AddFactory, Add)

}// namespace oa

#endif//OASIS_ADD_HPP
