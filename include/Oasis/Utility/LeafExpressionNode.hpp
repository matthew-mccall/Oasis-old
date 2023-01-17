//
// Created by Matthew McCall on 11/16/22.
//

#ifndef OASIS_LEAFEXPRESSIONNODE_HPP
#define OASIS_LEAFEXPRESSIONNODE_HPP

#include "Oasis/Expression.hpp"

namespace oa {

    class LeafExpressionNode : public Expression {
    public:
        bool addChild(std::unique_ptr<Expression> &&expr) final;
        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const final;
        void recurseForEachChild(std::function<void(const Expression &)> func) const final;

        [[nodiscard]] bool structurallyEquals(const Expression &other) const override;
    };

}// namespace oa

#define OA_DEFINE_LEAFEXPRESSION_COPY_FUNCS(CLASS_NAME)                       \
    std::unique_ptr<oa::Expression> CLASS_NAME::copy() const {                \
        return std::make_unique<CLASS_NAME>(*this);                           \
    }                                                                         \
    std::unique_ptr<oa::Expression> CLASS_NAME::copyWithoutChildren() const { \
        return std::make_unique<CLASS_NAME>(*this);                           \
    }

#endif//OASIS_LEAFEXPRESSIONNODE_HPP
