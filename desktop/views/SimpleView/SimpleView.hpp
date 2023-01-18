//
// Created by Matthew McCall on 11/9/22.
//

#ifndef OASIS_SIMPLEVIEW_HPP
#define OASIS_SIMPLEVIEW_HPP

#include "components/Menubar/Menubar.hpp"

class SimpleView : public wxFrame {
public:
    SimpleView();

private:
    void OnInit();

    Menubar menubar;
};


#endif//OASIS_SIMPLEVIEW_HPP
