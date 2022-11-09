//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_EXPONENT_HPP
#define OASIS_EXPONENT_HPP


#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    class Exponent final : public BinaryExpressionNode {
    public:
        Exponent(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(EXPONENT)
        OA_DECLARE_FACTORY(Exponent)
    };

}// namespace oa



#endif//OASIS_EXPONENT_HPP
