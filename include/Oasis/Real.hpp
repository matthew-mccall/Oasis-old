//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_REAL_HPP
#define OASIS_REAL_HPP

#include "Expression.hpp"

namespace oa {

    class Real final: public Expression {
    public:
        explicit Real(double val);
        Real(const Real &other);
        std::unique_ptr<oa::Expression> copy() override;
        bool addChild(std::unique_ptr<Expression> &&expr) override;

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        [[nodiscard]] double getVal() const;

        OA_EXPRESSION_TYPE(REAL)
        OA_DECLARE_FACTORY(Real)

    private:
        double _val;
    };

}// namespace oa

#endif//OASIS_REAL_HPP
