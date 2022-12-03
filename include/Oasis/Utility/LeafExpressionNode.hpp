//
// Created by Matthew McCall on 11/16/22.
//

#ifndef OASIS_LEAFEXPRESSIONNODE_HPP
#define OASIS_LEAFEXPRESSIONNODE_HPP

#include "Oasis/Expression.hpp"

namespace oa {

    template<typename T>
    class LeafExpressionNode : public Expression {
    public:
        bool addChild(std::unique_ptr<Expression> &&expr) final;
        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const final;
        void recurseForEachChild(std::function<void(const Expression &)> func) const final;

        std::unique_ptr<oa::Expression> copy() const override;
        std::unique_ptr<oa::Expression> copyWithoutChildren() const override;
    };
    template<typename T>
    std::unique_ptr<oa::Expression> LeafExpressionNode<T>::copy() const {
        return std::make_unique<T>(dynamic_cast<const T &>(*this));
    }
    template<typename T>
    std::unique_ptr<oa::Expression> LeafExpressionNode<T>::copyWithoutChildren() const {
        return std::make_unique<T>(dynamic_cast<const T &>(*this));
    }

    template<typename T>
    bool LeafExpressionNode<T>::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    template<typename T>
    void LeafExpressionNode<T>::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    template<typename T>
    void LeafExpressionNode<T>::recurseForEachChild(std::function<void(const Expression &)> func) const {
    }

}// namespace oa

#endif//OASIS_LEAFEXPRESSIONNODE_HPP
