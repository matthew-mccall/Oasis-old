//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BLANK_HPP
#define OASIS_BLANK_HPP

#include "Utility/LeafExpressionNode.hpp"

namespace oa {

    OA_DECLARE_FACTORY(BlankFactory, Blank)

    /**
     * A Blank expression is a placeholder.
     *
     * It is not meant to be evaluated, but replaced with an actual expression before evaluation
     */
    class Blank final : public LeafExpressionNode<BlankFactory> {
    public:
        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        [[nodiscard]] std::unique_ptr<oa::Expression> copy() const override;
        std::unique_ptr<oa::Expression> copyWithoutChildren() const override;

        bool operator==(const Expression &other) const override;

        OA_EXPRESSION_TYPE(BLANK)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_VALUE)
    };

    class BlankException : public Exception<std::logic_error> {
    public:
        explicit BlankException(const Expression &cause);
    };

}// namespace oa

#endif//OASIS_BLANK_HPP
