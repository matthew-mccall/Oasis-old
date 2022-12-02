//
// Created by Matthew McCall on 12/2/22.
//

#include "Oasis/Expression.hpp"

namespace oa {
    Exception::Exception(const std::string &string, const Expression &cause) : logic_error(string), _cause(cause) { }

    const Expression &Exception::getCause() const {
        return _cause;
    }
}// namespace oa