//
// Created by Andrew Nazareth on 11/9/22.
//

#include "Oasis/Expression.hpp"
#include "Oasis/Add.hpp"
#include "Oasis/Subtract.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Divide.hpp"
#include "Oasis/Exponent.hpp"
#include "Oasis/Variable.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Substitute.hpp"

int main(int argc, char** argv){
    double a, b;
    a = 3;
    b = 7;
    std::unique_ptr<oa::Add> add = oa::Add::Factory {
        oa::Real::Factory { a },
        oa::Variable::Factory { "c" }
    };

    auto [result, error, cause] = add->evaluate();
    assert(!error);


}