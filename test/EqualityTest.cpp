//
// Created by Matthew McCall on 11/11/22.
//

#include "Oasis/Oasis.hpp"

int main(int argc, const char **argv) {
    std::unique_ptr<oa::Expression> r1 = oa::RealFactory { 4 };
    std::unique_ptr<oa::Expression> r2 = oa::RealFactory { 4 };

    assert(*r1 == *r2);

    std::unique_ptr<oa::Expression> add = oa::AddFactory {
        oa::RealFactory { 3 },
        oa::RealFactory { 1 }
    };

    assert(*r1 == *add);
    assert(*r2 == *add);

    std::unique_ptr<oa::Expression> multiply = oa::MultiplyFactory {
        oa::RealFactory { 2 },
        oa::RealFactory { 2 }
    };

    assert(*multiply == *add);
}