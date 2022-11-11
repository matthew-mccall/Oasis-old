//
// Created by Andrew Nazareth on 11/9/22.
//

#include <cassert>

#include "Oasis/Substitute.hpp"
#include "Oasis/Variable.hpp"

namespace oa {

    std::unique_ptr<Expression> substitute(const std::unique_ptr<Expression> &expression, const std::string &var, const std::unique_ptr<Expression> &val) {
        std::unique_ptr<Expression> newTree;

        if (expression->getType() == Expression::Type::VARIABLE) {
            const Variable *variable = dynamic_cast<Variable *>(expression.get());
            if (variable->getRep() == var) {
                return val->copy();
            }
        }

        if (expression) {
            newTree = expression->copy();
            expression->forEachChild([&newTree, var, &val](const std::unique_ptr<Expression> &expr) {
                assert(newTree->addChild(substitute(expr, var, val)));
            });

            return newTree;
        }

        return nullptr;
    }

}// namespace oa
