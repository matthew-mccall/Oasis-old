//
// Created by Matthew McCall on 1/17/23.
//

#ifndef OASIS_BASECONVERTER_HPP
#define OASIS_BASECONVERTER_HPP

#include <wx/spinctrl.h>

#include "components/Menubar/Menubar.hpp"
class BaseConverter : public wxFrame {
public:
    BaseConverter();

private:
    void OnInit();
    void OnUpdate(wxCommandEvent &event);

    Menubar menubar;

    wxTextCtrl *inputText {};
    wxSpinCtrl *inputBase {};
    wxTextCtrl *outputText {};
    wxSpinCtrl *outputBase {};
};


#endif//OASIS_BASECONVERTER_HPP
