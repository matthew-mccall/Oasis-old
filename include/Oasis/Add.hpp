//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_ADD_HPP
#define OASIS_ADD_HPP

#include "Utility/BinaryExpressionNode.hpp"

namespace oa {

    class Add final : public BinaryExpressionNode {
    public:
        Add(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(ADD)
        OA_DECLARE_FACTORY(Add)
    };

}// namespace oa

#endif//OASIS_ADD_HPP
