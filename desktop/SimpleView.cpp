//
// Created by Matthew McCall on 11/9/22.
//

#include "spdlog/spdlog.h"

#include "SimpleView.hpp"

SimpleView::SimpleView() : wxFrame(nullptr, wxID_ANY, "Simple View") {
    OnInit();
}

void SimpleView::OnInit() {
    auto *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Copyright © 2022 Matthew McCall and Andrew Nazareth");

    Bind(wxEVT_MENU, &SimpleView::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &SimpleView::OnExit, this, wxID_EXIT);
}

void SimpleView::OnExit(wxCommandEvent &event) {
    Close(true);

    if (menuBar) {
        menuBar->Destroy();
    }
}

void SimpleView::OnAbout(wxCommandEvent &event) {
    wxMessageBox("Copyright © 2022 Matthew McCall and Andrew Nazareth",
                 "About Oasis Desktop", wxOK | wxICON_INFORMATION);
}
