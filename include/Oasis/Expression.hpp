//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_EXPRESSION_HPP
#define OASIS_EXPRESSION_HPP

#include <functional>
#include <memory>
#include <stdexcept>

#include "Utility/Types.hpp"

namespace oa {

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

        enum Category : std::uint16_t {
            EXPRESSION_CATEGORY_ARITHMETIC = 1,
            EXPRESSION_CATEGORY_BINARY_OPERANDS = 1 << 1,
            EXPRESSION_CATEGORY_UNARY_OPERANDS = 1 << 2,
            EXPRESSION_CATEGORY_VALUE = 1 << 3,
        };

        /**
         * Adds a child to this Expression. Expression dependent
         * @param expr The expression to add
         * @return true if the expression was added
         */
        virtual bool addChild(std::unique_ptr<Expression> &&expr) = 0;

        /**
         * Copies an Expression
         * @return A copy of this expression
         */
        [[nodiscard]] virtual std::unique_ptr<oa::Expression> copy() const = 0;

        virtual std::unique_ptr<oa::Expression> copyWithoutChildren() const = 0;

        /**
         * Evaluates this expression and child expressions
         * @return The evaluated expression
         */
        [[nodiscard]] virtual std::unique_ptr<Expression> evaluate() const = 0;

        /**
         * Calls func for each child
         * @param func The function to run on each child
         */
        virtual void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const = 0;

        /**
         * Recursively calls for each child and their children
         * @param func The function to call on all Nodes down the tree
         */
        virtual void recurseForEachChild(std::function<void(const Expression &)> func) const = 0;

        virtual bool operator==(const Expression &other) const = 0;

        bool operator!=(const Expression &other) const {
            return !(*this == other);
        }

        /**
         * Gets the type of this Expression
         * @return
         */
        [[nodiscard]] virtual Type getType() const = 0;
        virtual std::uint16_t getCategories() const = 0;

        virtual ~Expression() = default;
    };


    class Exception : public std::logic_error {
    public:
        Exception(const std::string &string, const Expression &cause);
        const Expression &getCause() const;

    private:
        const Expression &_cause;
    };

};// namespace oa

#define OA_EXPRESSION_TYPE(type)                                               \
    static Expression::Type getStaticType() { return Expression::Type::type; } \
    virtual Expression::Type getType() const override { return getStaticType(); }

#define OA_EXPRESSION_CATEGORIES(categories)                          \
    static std::uint16_t getStaticCategories() { return categories; } \
    virtual std::uint16_t getCategories() const override { return getStaticCategories(); }

#define OA_DECLARE_FACTORY(factoryName, type)                                                            \
                                                                                                         \
    class type;                                                                                          \
                                                                                                         \
    class factoryName {                                                                                  \
    public:                                                                                              \
        template<typename... Ts>                                                                         \
        explicit factoryName(Ts &&...args) : _ptr(std::make_unique<type>(std::forward<Ts>(args)...)) { } \
                                                                                                         \
        operator std::unique_ptr<Expression>() {                                                         \
                                                                                                         \
            std::unique_ptr<Expression> ptr;                                                             \
            ptr.reset((Expression *) _ptr.release());                                                    \
            return ptr;                                                                                  \
        }                                                                                                \
                                                                                                         \
        operator std::unique_ptr<type>() {                                                               \
            return std::move(_ptr);                                                                      \
        }                                                                                                \
                                                                                                         \
    private:                                                                                             \
        std::unique_ptr<type> _ptr;                                                                      \
    };

#endif//OASIS_EXPRESSION_HPP
