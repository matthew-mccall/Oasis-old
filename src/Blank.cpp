//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Blank.hpp"

namespace oa {

    std::unique_ptr<Expression> Blank::evaluate() const {
        throw Exception("Cannot evaluate Blank expression!", *this);
    }

    std::unique_ptr<oa::Expression> Blank::copy() const {
        return BlankFactory();
    }

    bool Blank::operator==(const Expression &other) const {
        return other.getType() == Expression::Type::BLANK;
    }
    std::unique_ptr<oa::Expression> Blank::copyWithoutChildren() const {
        return BlankFactory();
    }

}// namespace oa