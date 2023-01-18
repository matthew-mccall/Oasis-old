//
// Created by Matthew McCall on 11/9/22.
//

#include "spdlog/spdlog.h"

#include "wx/sizer.h"
#include "wx/webview.h"

#include "Arithmetic.hpp"
#include "components/KeypadButton/KeypadButton.hpp"

Arithmetic::Arithmetic() : wxFrame(nullptr, wxID_ANY, "Arithmetic") {
    OnInit();
}

void Arithmetic::OnInit() {
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

    menubar.OnExit([this](wxCommandEvent &event) {
        Close(true);
    },
                   this);

    SetMenuBar(menubar.getMenubar());
}
