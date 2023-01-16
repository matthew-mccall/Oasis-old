//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BLANK_HPP
#define OASIS_BLANK_HPP

#include "Utility/LeafExpressionNode.hpp"

namespace oa {

    /**
     * A Blank expression is a placeholder.
     *
     * It is not meant to be evaluated, but replaced with an actual expression before evaluation
     */
    class Blank final : public LeafExpressionNode {
    public:
        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        [[nodiscard]] bool equals(const Expression &other) const override;

        OA_EXPRESSION_TYPE(BLANK)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_VALUE)

        OA_OVERRIDE_COPY_FUNCS
    };

    class BlankException : public Exception<std::logic_error> {
    public:
        explicit BlankException(const Expression &cause);
    };

    OA_DECLARE_FACTORY(BlankFactory, Blank)

}// namespace oa

#endif//OASIS_BLANK_HPP
