//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_EXPONENT_HPP
#define OASIS_EXPONENT_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The exponent class exponentiates a base to a power
     */
    class Exponent final : public BinaryExpressionNode {
    public:
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
        std::unique_ptr<oa::Expression> copy() override;

        /**
         * Evaluates the operands and exponentiates the base to the power if they are Real operands
         * @return The result, error, and/or cause of error if there is an error
         */
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(EXPONENT)
        OA_DECLARE_FACTORY(Exponent)
    };

}// namespace oa


#endif//OASIS_EXPONENT_HPP
