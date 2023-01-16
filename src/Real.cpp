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

    bool Real::equals(const Expression &other) const {

        auto result = other.evaluate();

        if (result->getType() != Expression::Type::REAL) {
            return false;
        }

        const auto &realOther = dynamic_cast<const Real &>(*result);
        return realOther.getVal() == getVal();
    }

    OA_DEFINE_LEAFEXPRESSION_COPY_FUNCS(Real)

}// namespace oa