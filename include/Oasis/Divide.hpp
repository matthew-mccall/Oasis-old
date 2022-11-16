//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_DIVIDE_HPP
#define OASIS_DIVIDE_HPP


#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    OA_DECLARE_FACTORY(DivideFactory, Divide)

    /**
     * The Divide class adds divides expressions
     */
    class Divide final : public BinaryExpressionNode<DivideFactory> {
    public:
        Divide();

        /**
         * Creates a new Divide expression from two operands
         * @param left The left operand
         * @param right The right operand
         */
        Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        /**
         * Simplifies the operands and divides them if they are Real operands
         * @return The result, error, and/or cause of error if there is an error
         */
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(DIVIDE)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_ARITHMETIC | EXPRESSION_CATEGORY_BINARY_OPERANDS)
    };

}// namespace oa


#endif//OASIS_DIVIDE_HPP
