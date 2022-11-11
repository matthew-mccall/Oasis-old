//
// Created by Matthew McCall on 11/11/22.
//

#include "Oasis/Oasis.hpp"

int main(int argc, const char **argv) {
    std::unique_ptr<oa::Expression> r1 = oa::Real::Factory { 4 };
    std::unique_ptr<oa::Expression> r2 = oa::Real::Factory { 4 };

    assert(*r1 == *r2);

    std::unique_ptr<oa::Expression> add = oa::Add::Factory {
        oa::Real::Factory { 3 },
        oa::Real::Factory { 1 }
    };

    assert(*r1 == *add);
    assert(*r2 == *add);

    std::unique_ptr<oa::Expression> multiply = oa::Multiply::Factory {
        oa::Real::Factory { 2 },
        oa::Real::Factory { 2 }
    };

    assert(*multiply == *add);
}