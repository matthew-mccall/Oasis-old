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
            VARIABLE,
            ADD,
            SUBTRACT,
            MULTIPLY,
            DIVIDE,
            EXPONENT
        };

        virtual bool addChild(std::unique_ptr<Expression> &&expr) = 0;

        virtual std::unique_ptr<oa::Expression> copy() = 0;

        [[nodiscard]] virtual EvaluateReturnType evaluate() const = 0;
        [[nodiscard]] virtual Type getType() const = 0;

        virtual ~Expression() = default;
    };

}// namespace oa

#define OA_EXPRESSION_TYPE(type)                                               \
    static Expression::Type getStaticType() { return Expression::Type::type; } \
    virtual Expression::Type getType() const override { return getStaticType(); }

#define OA_DECLARE_FACTORY(type)                                                            \
                                                                                            \
    class Factory {                                                                         \
    public:                                                                                 \
        template<typename... Ts>                                                            \
        Factory(Ts &&...args) : _ptr(std::make_unique<type>(std::forward<Ts>(args)...)) { } \
                                                                                            \
        operator std::unique_ptr<Expression>() {                                            \
            return std::move(_ptr);                                                         \
        }                                                                                   \
                                                                                            \
        operator std::unique_ptr<type>() {                                                  \
            return std::move(_ptr);                                                         \
        }                                                                                   \
                                                                                            \
    private:                                                                                \
        std::unique_ptr<type> _ptr;                                                         \
    };

#endif//OASIS_EXPRESSION_HPP
