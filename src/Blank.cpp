//
// Created by Matthew McCall on 11/8/22.
//

#include "Oasis/Blank.hpp"

namespace oa {

    bool Blank::addChild(std::unique_ptr<Expression> &&expr) {
        return false;
    }

    EvaluateReturnType Blank::evaluate() const {
        return { nullptr, BLANK, this };
    }

    std::unique_ptr<oa::Expression> Blank::copy() const {
        return Blank::Factory {};
    }

    void Blank::forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const {
    }

    void Blank::recurseForEachChild(std::function<void(const Expression &)> func) const {
        func(*this);
    }
    bool Blank::operator==(const Expression &other) const {
        return other.getType() == Expression::Type::BLANK;
    }

}// namespace oa