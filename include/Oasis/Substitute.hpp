//
// Created by Andrew Nazareth on 11/9/22.
//

#ifndef OASIS_SUBSTITUTE_HPP
#define OASIS_SUBSTITUTE_HPP

#include <memory>
#include "Expression.hpp"

//to substitute value/expression into a variable
std::unique_ptr<oa::Expression> substitute(const std::unique_ptr<oa::Expression> &expression, std::string &var, const std::unique_ptr<oa::Expression> &val);

#endif//OASIS_SUBSTITUTE_HPP
