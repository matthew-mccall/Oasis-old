//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Real.hpp"

namespace oa {
    Real::Real(double val) : _val(val) { }

    Real::Real(const Real &other) : _val(other._val) {
    }

    EvaluateReturnType Real::evaluate() const {
        return EvaluateReturnType { Real::Factory { getVal() } };
    }

    bool Real::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    double Real::getVal() const {
        return _val;
    }
    std::unique_ptr<oa::Expression> Real::copy() {
        return Real::Factory { getVal() };
    }

    void Real::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) {
    }

    void Real::recurseForEachChild(std::function<void(const Expression &)> func) {
        func(*this);
    }
}// namespace oa