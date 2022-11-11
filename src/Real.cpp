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
    std::unique_ptr<oa::Expression> Real::copy() const {
        return Real::Factory { getVal() };
    }

    void Real::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    void Real::recurseForEachChild(std::function<void(const Expression &)> func) const {
        func(*this);
    }
    bool Real::operator==(const std::unique_ptr<Expression> &other) const {

        if (other->getType() != Expression::Type::REAL) {
            return false;
        }

        auto *realOther = dynamic_cast<Real *>(other.get());

        return realOther->getVal() == getVal();
    }
}// namespace oa