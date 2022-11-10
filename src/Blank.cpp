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
    std::unique_ptr<oa::Expression> Blank::copy() {
        return Blank::Factory{};
    }

}// namespace oa