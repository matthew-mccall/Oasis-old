//
// Created by Matthew McCall on 11/9/22.
//

#include "spdlog/spdlog.h"

#include "wx/sizer.h"
#include "wx/webview.h"

#include "SimpleView.hpp"
#include "components/KeypadButton/KeypadButton.hpp"

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

    auto *vStack = new wxBoxSizer(wxVERTICAL);

    auto *webView = wxWebView::New(this, wxID_ANY);
    webView->SetPage("<html><body><h1>Hello, world!</h1></body></html>", "");

    auto *keypad = new wxGridSizer(5, 4, 4, 4);

    keypad->Add(new KeypadButton(this, wxID_ANY, "Clear"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "("), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, ")"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "/"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "7"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "8"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "9"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "*"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "4"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "5"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "6"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "-"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "1"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "2"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "3"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "+"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "0"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "(-)"), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "."), wxSizerFlags().Expand().Border(wxALL, 0));
    keypad->Add(new KeypadButton(this, wxID_ANY, "Enter"), wxSizerFlags().Expand().Border(wxALL, 0));

    vStack->Add(webView, wxSizerFlags(1).Expand().Border(wxALL, 0));
    vStack->Add(keypad, wxSizerFlags(1).Expand().Border(wxALL, 0));

    SetSizerAndFit(vStack);

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
