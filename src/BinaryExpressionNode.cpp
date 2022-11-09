//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Utility/BinaryExpressionNode.hpp"
#include "Oasis/Blank.hpp"

namespace oa {

    bool BinaryExpressionNode::addChild(std::unique_ptr<Expression> &&expr) {

        if (_left->getType() == Expression::Type::BLANK) {
            _left = std::move(expr);
            return true;
        }

        if (_right->getType() == Expression::Type::BLANK) {
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

    BinaryExpressionNode::BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)) { }
    BinaryExpressionNode::BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult, EvaluateResultCode error, const Expression *cause) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)), error(error), cause(cause) { }
}// namespace oa