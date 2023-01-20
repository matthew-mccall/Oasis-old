//
// Created by Matthew McCall on 1/17/23.
//

#ifndef OASIS_TRUTHTABLE_HPP
#define OASIS_TRUTHTABLE_HPP

#include "wx/grid.h"

#include "components/Menubar/Menubar.hpp"

class TruthTable : public wxFrame {
public:
    TruthTable();

private:
    void OnInit();

    Menubar menubar;
    wxGrid *table {};
};


#endif//OASIS_TRUTHTABLE_HPP
