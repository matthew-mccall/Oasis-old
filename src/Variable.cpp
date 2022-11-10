//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Variable.hpp"

namespace oa {
    Variable::Variable(std::string rep): _rep(rep) {}
    Variable::Variable(oa::Variable &other) : _rep(other._rep) {}

    EvaluateReturnType Variable::evaluate() const {
        return EvaluateReturnType { Variable::Factory { getRep() } };
    }

    bool Variable::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    std::string Variable::getRep() const {
        return _rep;
    }
    std::unique_ptr<oa::Expression> Variable::copy() {
        return Variable::Factory{getRep()};
    }
}// namespace oa