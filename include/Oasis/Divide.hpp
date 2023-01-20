//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_DIVIDE_HPP
#define OASIS_DIVIDE_HPP


#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The Divide class adds divides expressions
     */
    class Divide final : public BinaryExpressionNode {
    public:
        Divide();

        /**
         * Creates a new Divide expression from two operands
         * @param left The left operand
         * @param right The right operand
         */
        Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        /**
         * Simplifies the operands and divides them if they are Real operands.
         *
         * @throws DivideByZeroException if the right operand is 0
         * @throws BlankException if either operand is blank
         * @return The simplified expression.
         */
        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        OA_EXPRESSION_TYPE(DIVIDE)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_ARITHMETIC | EXPRESSION_CATEGORY_BINARY_OPERANDS)

        OA_OVERRIDE_COPY_FUNCS
    };

    OA_DECLARE_FACTORY(DivideFactory, Divide)

    class DivideByZeroException : public Exception<std::domain_error> {
    public:
        explicit DivideByZeroException(const Expression &cause);
    };

}// namespace oa


#endif//OASIS_DIVIDE_HPP
