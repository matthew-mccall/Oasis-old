//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Variable.hpp"

namespace oa {
    Variable::Variable(std::string rep) : _rep(rep) { }
    Variable::Variable(oa::Variable &other) : _rep(other._rep) { }

    EvaluateReturnType Variable::evaluate() const {
        return EvaluateReturnType { Variable::Factory { getRep() } };
    }

    bool Variable::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    std::string Variable::getRep() const {
        return _rep;
    }

    std::unique_ptr<oa::Expression> Variable::copy() const {
        return Variable::Factory { getRep() };
    }

    void Variable::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    void Variable::recurseForEachChild(std::function<void(const Expression &)> func) const {
        func(*this);
    }

    bool Variable::operator==(const std::unique_ptr<Expression> &other) const {

        if (other->getType() != Expression::Type::VARIABLE) {
            return false;
        }

        auto *variableOther = dynamic_cast<Variable *>(other.get());

        return variableOther->getRep() == getRep();
    }
}// namespace oa