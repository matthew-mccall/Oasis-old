//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_SUBTRACT_HPP
#define OASIS_SUBTRACT_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    class Subtract final : public BinaryExpressionNode {
    public:
        Subtract(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(SUBTRACT)
        OA_DECLARE_FACTORY(Subtract)
    };

}// namespace oa

#endif//OASIS_SUBTRACT_HPP
