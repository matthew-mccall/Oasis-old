//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Real.hpp"

namespace oa {
    Real::Real(double val) : _val(val) { }

    Real::Real(const Real &other) : _val(other._val) {
    }

    EvaluateReturnType Real::evaluate() const {
        return EvaluateReturnType{ Real::Factory(getVal()) };
    }

    bool Real::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    double Real::getVal() const {
        return _val;
    }
}// namespace oa