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
         * Copies this expression and its children
         * @return A new Add expression whose children are copies of this expression
         */
        std::unique_ptr<oa::Expression> copy() override;

        /**
         * Evaluates the operands and adds them if they are Real operands
         * @return The result, error, and/or cause of error if there is an error
         */
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(ADD)
        OA_DECLARE_FACTORY(Add)
    };

}// namespace oa

#endif//OASIS_ADD_HPP
