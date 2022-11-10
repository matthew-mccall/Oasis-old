//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_MULTIPLY_HPP
#define OASIS_MULTIPLY_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    class Multiply final : public BinaryExpressionNode {
    public:
        Multiply(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);
        std::unique_ptr<oa::Expression> copy() override;
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(MULTIPLY)
        OA_DECLARE_FACTORY(Multiply)
    };

}// namespace oa


#endif//OASIS_MULTIPLY_HPP
