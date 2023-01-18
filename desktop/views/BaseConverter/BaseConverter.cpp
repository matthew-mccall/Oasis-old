//
// Created by Matthew McCall on 1/17/23.
//

#include <wx/spinctrl.h>

#include "BaseConverter.hpp"

BaseConverter::BaseConverter() : wxFrame(nullptr, wxID_ANY, "Base Converter") {
    OnInit();
}

void BaseConverter::OnInit() {
    auto *inputSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *inputLabel = new wxStaticText(this, wxID_ANY, "Input:");
    auto *inputText = new wxSpinCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000000, 0);
    auto *inputBaseLabel = new wxStaticText(this, wxID_ANY, "Base:");
    auto *inputBase = new wxSpinCtrl(this, wxID_ANY, "10", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 36, 10);

    inputSizer->Add(inputLabel, wxSizerFlags().Border(wxALL, 5));
    inputSizer->Add(inputText, wxSizerFlags().Expand().Border(wxALL, 5));
    inputSizer->Add(inputBaseLabel, wxSizerFlags().Border(wxALL, 5));
    inputSizer->Add(inputBase, wxSizerFlags().Expand().Border(wxALL, 5));

    auto *outputSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *outputLabel = new wxStaticText(this, wxID_ANY, "Output:");
    auto *outputText = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    auto *outputBaseLabel = new wxStaticText(this, wxID_ANY, "Base:");
    auto *outputBase = new wxSpinCtrl(this, wxID_ANY, "10", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 36, 10);

    outputSizer->Add(outputLabel, wxSizerFlags().Border(wxALL, 5));
    outputSizer->Add(outputText, wxSizerFlags().Expand().Border(wxALL, 5));
    outputSizer->Add(outputBaseLabel, wxSizerFlags().Border(wxALL, 5));
    outputSizer->Add(outputBase, wxSizerFlags().Expand().Border(wxALL, 5));

    auto *calculateButton = new wxButton(this, wxID_ANY, "Calculate");

    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(inputSizer, wxSizerFlags().Expand().Border(wxALL, 10));
    mainSizer->Add(outputSizer, wxSizerFlags().Expand().Border(wxALL, 10));
    mainSizer->Add(calculateButton, wxSizerFlags().Expand().Border(wxALL, 10));

    SetSizerAndFit(mainSizer);

    menubar.OnExit([this](wxCommandEvent &event) {
        Close(true);
    },
                   this);

    SetMenuBar(menubar.getMenubar());
    SetMaxSize(GetSize());
}
