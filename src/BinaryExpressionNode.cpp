//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Utility/BinaryExpressionNode.hpp"
#include "Oasis/Blank.hpp"

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

    BinaryExpressionNode::BinaryEvaluateReturnType BinaryExpressionNode::evaluateOperands() const {
        auto [leftResult, leftError, leftCause] = _left->evaluate();

        if (leftError) {
            return { nullptr, nullptr, leftError, leftCause };
        }

        auto [rightResult, rightError, rightCause] = _right->evaluate();

        if (rightError) {
            return { nullptr, nullptr, rightError, rightCause };
        }

        return { std::move(leftResult), std::move(rightResult) };
    }

    BinaryExpressionNode::BinaryExpressionNode() : _left(Blank::Factory()), _right(Blank::Factory()) { }
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

    bool BinaryExpressionNode::operator==(const Expression &other) const {

        auto [result, error, cause] = evaluate();

        assert(!error);

        if (other == *result) {
            return true;
        }

        auto [otherResult, otherError, otherCause] = evaluate();

        assert(!otherError);

        if (*otherResult == *result) {
            return true;
        }

        if (other.getType() != this->getType()) {
            return false;
        }

        const auto &binaryOther = dynamic_cast<const BinaryExpressionNode &>(other);

        auto [leftResult, rightResult, error1, cause1] = evaluateOperands();

        assert(!error1);

        auto [otherLeftResult, otherLeftError, otherLeftCause] = binaryOther._left->evaluate();

        assert(!otherLeftError);

        if (*otherLeftResult != *leftResult) {
            return false;
        }

        auto [otherRightResult, otherRightError, otherRightCause] = binaryOther._right->evaluate();

        assert(!otherRightError);

        if (*otherRightResult != *rightResult) {
            return false;
        }

        return true;
    }

    BinaryExpressionNode::BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)) { }
    BinaryExpressionNode::BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult, EvaluateResultCode error, const Expression *cause) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)), error(error), cause(cause) { }
}// namespace oa