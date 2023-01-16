//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_EXPONENT_HPP
#define OASIS_EXPONENT_HPP

#include <functional>

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The exponent class exponentiates a base to a power
     */
    class Exponent final : public BinaryExpressionNode {
    public:
        Exponent();

        /**
         * Creates a new Exponent expression from two operands
         * @param base The expression to be exponentiated
         * @param power The exponent
         */
        Exponent(std::unique_ptr<Expression> &&base, std::unique_ptr<Expression> &&power);

        /**
         * Copies this expression and its children
         * @return A new Exponent expression whose children are copies of this expression
         */

        /**
         * Evaluates the operands and exponentiates the base to the power if they are Real operands
         * @return The result, error, and/or cause of error if there is an error
         */
        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        OA_EXPRESSION_TYPE(EXPONENT)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_ARITHMETIC | EXPRESSION_CATEGORY_BINARY_OPERANDS)

        OA_DECLARE_BINARYEXPRESSION_COPY_FUNCS
    };

    OA_DECLARE_FACTORY(ExponentFactory, Exponent)

}// namespace oa


#endif//OASIS_EXPONENT_HPP
