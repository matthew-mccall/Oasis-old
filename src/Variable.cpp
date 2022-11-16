//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Variable.hpp"

namespace oa {
    Variable::Variable(std::string rep) : _rep(rep) { }
    Variable::Variable(oa::Variable &other) : _rep(other._rep) { }

    EvaluateReturnType Variable::evaluate() const {
        return EvaluateReturnType { VariableFactory { getRep() } };
    }

    bool Variable::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    std::string Variable::getRep() const {
        return _rep;
    }

    std::unique_ptr<oa::Expression> Variable::copy() const {
        return VariableFactory { getRep() };
    }

    void Variable::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    void Variable::recurseForEachChild(std::function<void(const Expression &)> func) const {
        func(*this);
    }

    bool Variable::operator==(const Expression &other) const {

        auto [result, error, cause] = other.evaluate();

        if (result->getType() != Expression::Type::VARIABLE) {
            return false;
        }

        const auto &variableOther = dynamic_cast<const Variable &>(*result);
        return variableOther.getRep() == getRep();
    }

    std::unique_ptr<oa::Expression> Variable::copyWithoutChildren() const {
        return VariableFactory { getRep() };
    }
}// namespace oa