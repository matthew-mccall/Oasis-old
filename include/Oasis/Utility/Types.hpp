//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_TYPES_HPP
#define OASIS_TYPES_HPP

#include <utility>

#include "gsl/pointers"

namespace oa
{

#ifdef NDEBUG
    template<typename T>
    using NotNull = gsl::not_null<T>;
#else
    template<typename T>
    using NotNull = gsl::strict_not_null<T>;
#endif

    template<typename T>
    using Owner = gsl::owner<T>;

}

#endif//OASIS_TYPES_HPP
