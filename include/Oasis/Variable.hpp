//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_VARIABLE_HPP
#define OASIS_VARIABLE_HPP

#include "Expression.hpp"
#include "Utility/LeafExpressionNode.hpp"

namespace oa {

    /**
     * An arbitrary variable
     */
    class Variable final : public LeafExpressionNode<Variable> {
    public:
        explicit Variable(std::string rep);
        Variable(const Variable &other);

        [[nodiscard]] std::unique_ptr<Expression> evaluate() const override;

        [[nodiscard]] std::string getRep() const;

        bool equals(const Expression &other) const override;

        OA_EXPRESSION_TYPE(VARIABLE)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_VALUE)

    private:
        std::string _rep;//representation eg x
    };

    OA_DECLARE_FACTORY(VariableFactory, Variable)

}// namespace oa


#endif//OASIS_VARIABLE_HPP
