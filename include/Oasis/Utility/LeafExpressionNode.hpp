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
    };

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
