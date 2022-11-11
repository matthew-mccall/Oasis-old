//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_SUBTRACT_HPP
#define OASIS_SUBTRACT_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    /**
     * The Add class subtracts two expressions
     */
    class Subtract final : public BinaryExpressionNode {
    public:
        Subtract();

        Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);
        std::unique_ptr<oa::Expression> copy() const override;
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(SUBTRACT)
        OA_DECLARE_FACTORY(Subtract)
    };

}// namespace oa

#endif//OASIS_SUBTRACT_HPP
