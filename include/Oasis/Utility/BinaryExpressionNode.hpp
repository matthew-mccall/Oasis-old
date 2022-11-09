//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_BINARYEXPRESSIONNODE_HPP
#define OASIS_BINARYEXPRESSIONNODE_HPP

#include "Oasis/Expression.hpp"

#include "Types.hpp"

namespace oa {

    class BinaryExpressionNode : public Expression {
    public:
        BinaryExpressionNode();
        BinaryExpressionNode(std::unique_ptr<Expression> &&left, std::unique_ptr<Expression> &&right);

        bool addChild(std::unique_ptr<Expression> &&expr) final;

    protected:
        struct BinaryEvaluateReturnType {

            BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult);
            BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult, EvaluateResultCode error, const Expression *cause);

            std::unique_ptr<Expression> leftResult;
            std::unique_ptr<Expression> rightResult;
            EvaluateResultCode error = SUCCESS;
            const Expression *cause = nullptr;
        };

        [[nodiscard]] BinaryEvaluateReturnType evaluateOperands() const;

        std::unique_ptr<Expression> _left, _right;
    };

}// namespace oa

#endif//OASIS_BINARYEXPRESSIONNODE_HPP
