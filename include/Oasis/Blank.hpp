//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BLANK_HPP
#define OASIS_BLANK_HPP

#include "Expression.hpp"

namespace oa {

    /**
     * A Blank expression is a placeholder.
     *
     * It is not meant to be evaluated, but replaced with an actual expression before evaluation
     */
    class Blank final : public Expression {
    public:
        bool addChild(std::unique_ptr<Expression> &&expr) override;
        [[nodiscard]] EvaluateReturnType evaluate() const override;
        std::unique_ptr<oa::Expression> copy() override;
        OA_EXPRESSION_TYPE(BLANK)
        OA_DECLARE_FACTORY(Blank)
    };

}// namespace oa

#endif//OASIS_BLANK_HPP
