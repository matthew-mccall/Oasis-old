//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_VARIABLE_HPP
#define OASIS_VARIABLE_HPP

#include "Expression.hpp"
#include <string>//may change string to char later

namespace oa {

    OA_DECLARE_FACTORY(VariableFactory, Variable)

    /**
     * An arbitrary variable
     */
    class Variable final : public Expression {
    public:
        explicit Variable(std::string rep);
        Variable(Variable &other);

        [[nodiscard]] std::unique_ptr<oa::Expression> copy() const override;
        std::unique_ptr<oa::Expression> copyWithoutChildren() const override;

        bool addChild(std::unique_ptr<Expression> &&expr) override;

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const override;
        void recurseForEachChild(std::function<void(const Expression &)> func) const override;

        //[[nodiscard]] double getVal() const;
        [[nodiscard]] std::string getRep() const;

        bool operator==(const Expression &other) const override;

        OA_EXPRESSION_TYPE(VARIABLE)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_VALUE)

    private:
        //double _val;
        std::string _rep;//representation eg x
    };

}// namespace oa


#endif//OASIS_VARIABLE_HPP
