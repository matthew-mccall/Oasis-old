//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_DIVIDE_HPP
#define OASIS_DIVIDE_HPP


#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    class Divide final : public BinaryExpressionNode {
    public:
        Divide(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);
        std::unique_ptr<oa::Expression> copy() override;
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(DIVIDE)
        OA_DECLARE_FACTORY(Divide)
    };

}// namespace oa


#endif//OASIS_DIVIDE_HPP
