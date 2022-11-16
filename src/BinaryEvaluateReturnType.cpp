//
// Created by Matthew McCall on 11/15/22.
//

#include "Oasis/Utility/BinaryExpressionNode.hpp"

namespace oa {

    BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)) { }
    BinaryEvaluateReturnType::BinaryEvaluateReturnType(std::unique_ptr<Expression> &&leftResult, std::unique_ptr<Expression> &&rightResult, EvaluateResultCode error, const Expression *cause) : leftResult(std::move(leftResult)), rightResult(std::move(rightResult)), error(error), cause(cause) { }

}// namespace oa
