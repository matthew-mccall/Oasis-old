//
// Created by Matthew McCall on 1/17/23.
//

#ifndef OASIS_BASECONVERTER_HPP
#define OASIS_BASECONVERTER_HPP


#include "components/Menubar/Menubar.hpp"
class BaseConverter : public wxFrame {
public:
    BaseConverter();

private:
    void OnInit();

    Menubar menubar;
};


#endif//OASIS_BASECONVERTER_HPP
