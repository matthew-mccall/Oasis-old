//
// Created by Matthew McCall on 11/9/22.
//

#ifndef OASIS_ARITHMETIC_HPP
#define OASIS_ARITHMETIC_HPP

#include "components/Menubar/Menubar.hpp"

class Arithmetic : public wxFrame {
public:
    Arithmetic();

private:
    void OnInit();

    Menubar menubar;
};


#endif//OASIS_ARITHMETIC_HPP
