//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Variable.hpp"

namespace oa {
    Variable::Variable(std::string rep) : _rep(rep) { }
    Variable::Variable(const Variable &other) : _rep(other._rep) { }

    std::unique_ptr<Expression> Variable::evaluate() const {
        return VariableFactory { getRep() };
    }


    std::string Variable::getRep() const {
        return _rep;
    }

    bool Variable::operator==(const Expression &other) const {

        auto result = other.evaluate();

        if (result->getType() != Expression::Type::VARIABLE) {
            return false;
        }

        const auto &variableOther = dynamic_cast<const Variable &>(*result);
        return variableOther.getRep() == getRep();
    }

}// namespace oa