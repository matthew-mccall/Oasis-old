//
// Created by Matthew McCall on 1/17/23.
//

#ifndef OASIS_MENUBAR_HPP
#define OASIS_MENUBAR_HPP

#include <functional>

class Menubar {
public:
    Menubar();

    [[nodiscard]] wxMenuBar *getMenubar() const;

    void OnAbout(wxCommandEvent &event);
    void OnBases(wxCommandEvent &event);
    void OnTruthTable(wxCommandEvent &event);
    void OnAlgebra(wxCommandEvent &event);
    void OnArithmetic(wxCommandEvent &event);

    void OnExit(const std::function<void(wxCommandEvent &)> &exitFunction, wxFrame *frame);

private:
    void OnInit();

    wxMenuBar *menubar {};
};


#endif//OASIS_MENUBAR_HPP
