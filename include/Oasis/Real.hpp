//
// Created by Matthew McCall on 11/8/22.
//

#ifndef OASIS_REAL_HPP
#define OASIS_REAL_HPP

#include "Expression.hpp"

namespace oa {

    OA_DECLARE_FACTORY(RealFactory, Real)

    /**
     * Represents a Real number
     */
    class Real final : public Expression {
    public:
        explicit Real(double val);
        Real(const Real &other);

        [[nodiscard]] std::unique_ptr<oa::Expression> copy() const override;
        [[nodiscard]] std::unique_ptr<oa::Expression> copyWithoutChildren() const override;

        bool addChild(std::unique_ptr<Expression> &&expr) override;

        [[nodiscard]] EvaluateReturnType evaluate() const override;

        void forEachChild(std::function<void(const std::unique_ptr<Expression> &)> func) const override;
        void recurseForEachChild(std::function<void(const Expression &)> func) const override;

        [[nodiscard]] double getVal() const;

        bool operator==(const Expression &other) const override;

        OA_EXPRESSION_TYPE(REAL)
        OA_EXPRESSION_CATEGORIES(EXPRESSION_CATEGORY_VALUE)

    private:
        double _val;
    };

}// namespace oa

#endif//OASIS_REAL_HPP
