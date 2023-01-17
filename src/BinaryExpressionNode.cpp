//
// Created by Matthew McCall on 1/16/23.
//

#include "Oasis/Utility/BinaryExpressionNode.hpp"

namespace oa {

    bool BinaryExpressionNode::addChild(std::unique_ptr<Expression> &&expr) {

        if (_left->getType() == Expression::Type::BLANK || !_left) {
            _left = std::move(expr);
            return true;
        }

        if (_right->getType() == Expression::Type::BLANK || !_right) {
            _right = std::move(expr);
            return true;
        }

        return false;
    }


    BinaryEvaluateReturnType BinaryExpressionNode::evaluateOperands() const {
        auto leftResult = _left->evaluate();
        auto rightResult = _right->evaluate();

        if (this->getType() == Expression::Type::MULTIPLY) {
            if (rightResult->getType() == Expression::Type::REAL && leftResult->getType() != Expression::Type::REAL) {
                std::swap(leftResult, rightResult);
            }
        }

        return { std::move(leftResult), std::move(rightResult) };
    }


    BinaryExpressionNode::BinaryExpressionNode() : _left(BlankFactory()), _right(BlankFactory()) { }


    BinaryExpressionNode::BinaryExpressionNode(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : _left(std::move(left)), _right(std::move(right)) { }


    void BinaryExpressionNode::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
        func(_left);
        func(_right);
    }


    void BinaryExpressionNode::recurseForEachChild(std::function<void(const Expression &)> func) const {
        _left->recurseForEachChild(func);
        _right->recurseForEachChild(func);

        func(*this);
    }


    bool BinaryExpressionNode::equals(const Expression &other) const {
        auto result = evaluate();
        auto otherResult = other.evaluate();

        if (!(result->getCategories() & EXPRESSION_CATEGORY_BINARY_OPERANDS) ||
            !(otherResult->getCategories() & EXPRESSION_CATEGORY_BINARY_OPERANDS)) {
            return *result == *otherResult;
        }

        if (other.getType() != this->getType()) {
            return false;
        }

        const auto &binaryResult = dynamic_cast<const BinaryExpressionNode &>(*result);
        const auto &binaryOther = dynamic_cast<const BinaryExpressionNode &>(*otherResult);

        auto [leftResult, rightResult] = binaryResult.evaluateOperands();
        auto [otherLeftResult, otherRightResult] = binaryOther.evaluateOperands();

        return (*leftResult == *otherLeftResult) && (*rightResult == *otherRightResult);
    }

    const std::unique_ptr<Expression> &BinaryExpressionNode::getLeft() const {
        return _left;
    }


    const std::unique_ptr<Expression> &BinaryExpressionNode::getRight() const {
        return _right;
    }

    bool BinaryExpressionNode::structurallyEquals(const Expression &other) const {

        if (other.getType() == Expression::Type::BLANK) {
            return true;
        }

        if (other.getType() != this->getType()) {
            return false;
        }

        const auto &binaryOther = dynamic_cast<const BinaryExpressionNode &>(other);

        auto [leftResult, rightResult] = evaluateOperands();

        // We will treat blanks as wildcards, so we don't need to check the other side.
        return leftResult->structurallyEquals(*binaryOther._left) &&
               rightResult->structurallyEquals(*binaryOther._right);
    }

}// namespace oa