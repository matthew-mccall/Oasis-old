//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_MULTIPLY_HPP
#define OASIS_MULTIPLY_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The Multiply class multiplies two expressions
     */
    class Multiply final : public BinaryExpressionNode {
    public:
        Multiply();

        /**
         * Creates a new Multiply expression from two operands
         * @param left The left operand
         * @param right The right operand
         */
        Multiply(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        /**
         * Copies this expression and its children
         * @return A new Multiply expression whose children are copies of this expression
         */
        std::unique_ptr<oa::Expression> copy() const override;

        /**
         * Evaluates the operands and multiplies them if they are Real operands
         * @return The result, error, and/or cause of error if there is an error
         */
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(MULTIPLY)
        OA_DECLARE_FACTORY(Multiply)
    };

}// namespace oa


#endif//OASIS_MULTIPLY_HPP
