//
// Created by Matthew McCall on 1/16/23.
//

#include "Oasis/Utility/LeafExpressionNode.hpp"

namespace oa {

    bool LeafExpressionNode::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    void LeafExpressionNode::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    void LeafExpressionNode::recurseForEachChild(std::function<void(const Expression &)> func) const {
    }

}// namespace oa