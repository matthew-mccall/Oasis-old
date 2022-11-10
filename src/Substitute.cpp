//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Substitute.hpp"
std::unique_ptr<oa::Expression> substitute(const std::unique_ptr<oa::Expression> &expression, std::string &var, const std::unique_ptr<oa::Expression> &val) {
    auto copy = expression->copy();
    return copy;
}
