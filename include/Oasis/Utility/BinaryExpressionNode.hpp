//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BINARYEXPRESSIONNODE_HPP
#define OASIS_BINARYEXPRESSIONNODE_HPP

#include "Oasis/Expression.hpp"

#include "Oasis/Blank.hpp"
#include "Types.hpp"

namespace oa {

    struct BinaryEvaluateReturnType {

        BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult);
        BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult, EvaluateResultCode error, const Expression *cause);

        std::unique_ptr<Expression> leftResult;
        std::unique_ptr<Expression> rightResult;
        EvaluateResultCode error = SUCCESS;
        const Expression *cause = nullptr;
    };

    /**
     * Helper class for Expressions that have two children/operands
     */
    template<typename T>
    class BinaryExpressionNode : public Expression {
    public:
        BinaryExpressionNode();
        BinaryExpressionNode(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        [[nodiscard]] std::unique_ptr<oa::Expression> copy() const final;
        [[nodiscard]] std::unique_ptr<oa::Expression> copyWithoutChildren() const final;

        bool addChild(std::unique_ptr<Expression> &&expr) final;
        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const final;
        void recurseForEachChild(std::function<void(const Expression &)> func) const override;

        bool operator==(const Expression &other) const final;

        [[nodiscard]] const std::unique_ptr<Expression> &getLeft() const;
        [[nodiscard]] const std::unique_ptr<Expression> &getRight() const;

    protected:
        [[nodiscard]] BinaryEvaluateReturnType evaluateOperands() const;

        std::unique_ptr<Expression> _left, _right;
    };

    template<typename T>
    bool BinaryExpressionNode<T>::addChild(std::unique_ptr<Expression> &&expr) {

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

    template<typename T>
    BinaryEvaluateReturnType BinaryExpressionNode<T>::evaluateOperands() const {
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

    template<typename T>
    BinaryExpressionNode<T>::BinaryExpressionNode() : _left(BlankFactory()), _right(BlankFactory()) { }

    template<typename T>
    BinaryExpressionNode<T>::BinaryExpressionNode(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right) : _left(std::move(left)), _right(std::move(right)) { }

    template<typename T>
    void BinaryExpressionNode<T>::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
        func(_left);
        func(_right);
    }

    template<typename T>
    void BinaryExpressionNode<T>::recurseForEachChild(std::function<void(const Expression &)> func) const {
        _left->recurseForEachChild(func);
        _right->recurseForEachChild(func);

        func(*this);
    }

    template<typename T>
    bool BinaryExpressionNode<T>::operator==(const Expression &other) const {

        auto [result, error, cause] = evaluate();
        assert(!error);

        auto [otherResult, otherError, otherCause] = evaluate();
        assert(!otherError);

        if (
                (result->getCategories() & EXPRESSION_CATEGORY_BINARY_OPERANDS) &&
                (otherResult->getCategories() & EXPRESSION_CATEGORY_BINARY_OPERANDS)) {
            if (other.getType() != this->getType()) {
                return false;
            }

            const auto &binaryResult = dynamic_cast<const BinaryExpressionNode &>(*result);
            const auto &binaryOther = dynamic_cast<const BinaryExpressionNode &>(*otherResult);

            auto [leftResult, rightResult, error1, cause1] = binaryResult.evaluateOperands();
            assert(!error1);

            auto [otherLeftResult, otherRightResult, otherError1, otherCause1] = binaryOther.evaluateOperands();
            assert(!otherError1);

            return (*leftResult == *otherLeftResult) && (*rightResult == *otherRightResult);
        }

        return *result == *otherResult;
    }

    template<typename T>
    const std::unique_ptr<Expression> &BinaryExpressionNode<T>::getLeft() const {
        return _left;
    }

    template<typename T>
    const std::unique_ptr<Expression> &BinaryExpressionNode<T>::getRight() const {
        return _right;
    }

    template<typename T>
    std::unique_ptr<oa::Expression> BinaryExpressionNode<T>::copy() const {
        return T(_left->copy(), _right->copy());
    }
    template<typename T>
    std::unique_ptr<oa::Expression> BinaryExpressionNode<T>::copyWithoutChildren() const {
        return T();
    }

}// namespace oa

#endif//OASIS_BINARYEXPRESSIONNODE_HPP
