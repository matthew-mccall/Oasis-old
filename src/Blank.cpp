//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Blank.hpp"

namespace oa {

    std::unique_ptr<Expression> Blank::evaluate() const {
        throw BlankException(*this);
    }

    bool Blank::equals(const Expression &other) const {
        return other.getType() == Expression::Type::BLANK;
    }

    BlankException::BlankException(const Expression &cause) : Exception(cause, "Cannot evaluate Blank expression!") { }
}// namespace oa