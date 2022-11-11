//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_SUBSTITUTE_HPP
#define OASIS_SUBSTITUTE_HPP

#include "Expression.hpp"
#include <memory>

namespace oa {

    /**
     * Substitutes an Expression into a variable
     * @param expression The Expression to search for variables
     * @param var The variable to substitute
     * @param val The Expression to substitute with
     * @return The expression with the substituted val
     */
    std::unique_ptr<oa::Expression> substitute(const std::unique_ptr<oa::Expression> &expression, const std::string &var, const std::unique_ptr<oa::Expression> &val);

}// namespace oa

#endif//OASIS_SUBSTITUTE_HPP
