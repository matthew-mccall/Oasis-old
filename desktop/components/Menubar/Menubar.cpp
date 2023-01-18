//
// Created by Matthew McCall on 1/17/23.
//

#include "Menubar.hpp"
#include "views/Arithmetic/Arithmetic.hpp"
#include "views/BaseConverter/BaseConverter.hpp"
#include "views/TruthTable/TruthTable.hpp"


enum MenuID {
    BASES = wxID_HIGHEST + 1,
    TRUTH_TABLE,
    ARITHMETIC,
    ALGEBRA,
};

Menubar::Menubar() {
    OnInit();
}

void Menubar::OnInit() {
    auto *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    auto *menuCalculator = new wxMenu;
    menuCalculator->Append(ARITHMETIC, "Arithmetic", "Arithmetic");
    menuCalculator->Append(ALGEBRA, "Algebra", "Algebra");

    auto *menuBases = new wxMenu;
    menuBases->Append(MenuID::BASES, "Bases...", "Convert between bases");

    auto *menuLogic = new wxMenu;
    menuLogic->Append(MenuID::TRUTH_TABLE, "Truth Tables...", "Truth Tables");

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    menubar = new wxMenuBar;
    menubar->Append(menuFile, "&File");
    menubar->Append(menuBases, "&Bases");
    menubar->Append(menuCalculator, "&Calculator");
    menubar->Append(menuLogic, "&Logic");
    menubar->Append(menuHelp, "&Help");

    menubar->Bind(wxEVT_MENU, &Menubar::OnAbout, this, wxID_ABOUT);
    menubar->Bind(wxEVT_MENU, &Menubar::OnAlgebra, this, MenuID::ALGEBRA);
    menubar->Bind(wxEVT_MENU, &Menubar::OnArithmetic, this, MenuID::ARITHMETIC);
    menubar->Bind(wxEVT_MENU, &Menubar::OnBases, this, MenuID::BASES);
    menubar->Bind(wxEVT_MENU, &Menubar::OnTruthTable, this, MenuID::TRUTH_TABLE);
}

wxMenuBar *Menubar::getMenubar() const {
    return menubar;
}

void Menubar::OnAbout(wxCommandEvent &event) {
    wxMessageBox("Copyright © 2022 Matthew McCall and Andrew Nazareth",
                 "About Oasis Desktop", wxOK | wxICON_INFORMATION);
}

void Menubar::OnBases(wxCommandEvent &event) {
    auto *baseConverter = new BaseConverter();
    baseConverter->Show(true);
}

void Menubar::OnTruthTable(wxCommandEvent &event) {
    auto *truthTable = new TruthTable();
    truthTable->Show(true);
}

void Menubar::OnAlgebra(wxCommandEvent &event) {
    wxMessageBox("Algebra is not yet implemented", "Algebra", wxOK | wxICON_INFORMATION);
}

void Menubar::OnArithmetic(wxCommandEvent &event) {
    auto *arithmetic = new Arithmetic();
    arithmetic->Show(true);
}

void Menubar::OnExit(const std::function<void(wxCommandEvent &)> &exitFunction, wxFrame *frame) {
    frame->Bind(wxEVT_MENU, exitFunction, wxID_EXIT);
}
