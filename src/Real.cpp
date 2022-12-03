//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Real.hpp"

namespace oa {
    Real::Real(double val) : _val(val) { }

    Real::Real(const Real &other) : _val(other._val) {
    }

    std::unique_ptr<Expression> Real::evaluate() const {
        return RealFactory { getVal() };
    }

    double Real::getVal() const {
        return _val;
    }
    std::unique_ptr<oa::Expression> Real::copy() const {
        return RealFactory { getVal() };
    }

    std::unique_ptr<oa::Expression> Real::copyWithoutChildren() const {
        return RealFactory { getVal() };
    }

    bool Real::equals(const Expression &other) const {

        auto result = other.evaluate();

        if (result->getType() != Expression::Type::REAL) {
            return false;
        }

        const auto &realOther = dynamic_cast<const Real &>(*result);
        return realOther.getVal() == getVal();
    }

}// namespace oa