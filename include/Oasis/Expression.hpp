//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_EXPRESSION_HPP
#define OASIS_EXPRESSION_HPP

#include <memory>

#include "Utility/Types.hpp"

namespace oa {

    class Expression;

    enum EvaluateResultCode {
        SUCCESS = 0,
        BLANK,
    };

    struct EvaluateReturnType {
        explicit EvaluateReturnType(std::unique_ptr<Expression> &&result) : result(std::move(result)) { }

        EvaluateReturnType(std::unique_ptr<Expression> &&result, EvaluateResultCode error, const Expression *cause) : result(std::move(result)), error(error), cause(cause) { }

        std::unique_ptr<Expression> result;
        EvaluateResultCode error = SUCCESS;
        const Expression *cause = nullptr;
    };

    class Expression {
    public:
        enum class Type {
            REAL,
            BLANK,
            ADD,
            SUBTRACT,
            MULTIPLY,
            DIVIDE
        };

        virtual bool addChild(std::unique_ptr<Expression> &&expr) = 0;

        [[nodiscard]] virtual EvaluateReturnType evaluate() const = 0;
        [[nodiscard]] virtual Type getType() const = 0;

        virtual ~Expression() = default;
    };

}// namespace oa

#define OA_EXPRESSION_TYPE(type)                                               \
    static Expression::Type getStaticType() { return Expression::Type::type; } \
    virtual Expression::Type getType() const override { return getStaticType(); }

#define OA_DECLARE_FACTORY(type)                                  \
    template<typename... Ts>                                      \
    static std::unique_ptr<type> Factory(Ts &&...args) {          \
        return std::make_unique<type>(std::forward<Ts>(args)...); \
    }
#endif//OASIS_EXPRESSION_HPP
