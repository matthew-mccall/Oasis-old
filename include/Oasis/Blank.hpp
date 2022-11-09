//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BLANK_HPP
#define OASIS_BLANK_HPP

#include "Expression.hpp"

namespace oa {

    class Blank : public Expression {
    public:
        bool addChild(std::unique_ptr<Expression> &&expr) override;
        [[nodiscard]] EvaluateReturnType evaluate() const override;

        OA_EXPRESSION_TYPE(BLANK)
        OA_DECLARE_FACTORY(Blank)
    };

}// namespace oa

#endif//OASIS_BLANK_HPP
