//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BINARYEXPRESSIONNODE_HPP
#define OASIS_BINARYEXPRESSIONNODE_HPP

#include <cassert>
#include <functional>
#include <optional>

#include "Oasis/Expression.hpp"

#include "Oasis/Blank.hpp"
#include "Types.hpp"

namespace oa {

    struct BinaryEvaluateReturnType {
        std::unique_ptr<Expression> leftResult;
        std::unique_ptr<Expression> rightResult;
    };

    /**
     * Helper class for Expressions that have two children/operands
     */
    class BinaryExpressionNode : public Expression {
    public:
        BinaryExpressionNode();
        BinaryExpressionNode(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        bool addChild(std::unique_ptr<Expression> &&expr) final;
        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const final;
        void recurseForEachChild(std::function<void(const Expression &)> func) const override;

        [[nodiscard]] bool equals(const Expression &other) const final;

        [[nodiscard]] const std::unique_ptr<Expression> &getLeft() const;
        [[nodiscard]] const std::unique_ptr<Expression> &getRight() const;

    protected:
        [[nodiscard]] BinaryEvaluateReturnType evaluateOperands() const;

        /**
         * Compares the left and right operands of this expression to the left and right operands of another expression.
         * If the left or right operands of the other expression is blank, then those operands are compared true.
         * @param other
         * @return true, if the left and right operands of this expression are equal to the left and right operands of the other expression
         */
        [[nodiscard]] bool structurallyEquals(const Expression &other) const final;

        std::unique_ptr<Expression> _left, _right;
    };

}// namespace oa

#define OA_DEFINE_BINARYEXPRESSION_COPY_FUNCS(CLASS_NAME)                     \
    std::unique_ptr<oa::Expression> CLASS_NAME::copy() const {                \
        return std::make_unique<CLASS_NAME>(_left->copy(), _right->copy());   \
    }                                                                         \
    std::unique_ptr<oa::Expression> CLASS_NAME::copyWithoutChildren() const { \
        return std::make_unique<CLASS_NAME>();                                \
    }

#endif//OASIS_BINARYEXPRESSIONNODE_HPP
