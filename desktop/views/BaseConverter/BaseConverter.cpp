//
// Created by Matthew McCall on 1/17/23.
//
#include <cmath>
#include <cstdlib>

#include <wx/spinctrl.h>

#include "BaseConverter.hpp"

void convertBase(const std::string &input, unsigned inputBase, wxTextCtrl *output, unsigned outputBase) {

    // Convert one base to another including decimal places.
    // This is done by converting the input to a decimal number, then converting the decimal number to the output base.
    // This is done by repeatedly dividing the input by the output base and taking the remainder.
    // The remainders are then converted to the output base and concatenated together.
    // The decimal places are then converted by repeatedly multiplying the decimal places by the output base and taking the integer part.
    // The integer parts are then converted to the output base and concatenated together.

    // Convert the input to a decimal number.
    double decimal = 0;
    auto decimalPoint = static_cast<long>(input.find('.'));

    if (decimalPoint == std::string::npos) {
        decimalPoint = static_cast<long>(input.size());
    }

    // 10.1

    for (unsigned i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == '.') {
            continue;
        }

        long power = decimalPoint - i - 1;
        if (i > decimalPoint) {
            power = decimalPoint - i;
        }

        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * pow(inputBase, power);
        } else if (c >= 'A' && c <= 'Z') {
            decimal += (c - 'A' + 10) * pow(inputBase, power);
        } else if (c >= 'a' && c <= 'z') {
            decimal += (c - 'a' + 10) * pow(inputBase, power);
        }
    }

    // Convert the decimal number to the output base.
    std::string outputString;
    while (decimal >= 1) {
        unsigned remainder = (unsigned) fmod(decimal, outputBase);
        if (remainder < 10) {
            outputString += (char) (remainder + '0');
        } else {
            outputString += (char) (remainder - 10 + 'A');
        }
        decimal = (decimal - remainder) / outputBase;
    }

    // Reverse the output string.
    std::string outputStringReversed;
    for (int i = (int) outputString.size() - 1; i >= 0; i--) {
        outputStringReversed += outputString[i];
    }

    // Convert the decimal places to the output base.
    std::string decimalPlaces;
    double decimalPlacesDecimal = 0;
    for (unsigned i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == '.') {
            for (unsigned j = i + 1; j < input.size(); j++) {
                char c = input[j];
                if (c >= '0' && c <= '9') {
                    decimalPlacesDecimal += (c - '0') * pow(inputBase, i - j);
                } else if (c >= 'A' && c <= 'Z') {
                    decimalPlacesDecimal += (c - 'A' + 10) * pow(inputBase, i - j);
                } else if (c >= 'a' && c <= 'z') {
                    decimalPlacesDecimal += (c - 'a' + 10) * pow(inputBase, i - j);
                }
            }
            break;
        }
    }

    unsigned decimalPlacesCount = 0;
    while (decimalPlacesDecimal > 0 && decimalPlacesCount < 15) {
        auto integerPart = static_cast<unsigned>(decimalPlacesDecimal);
        if (integerPart < 10) {
            decimalPlaces += static_cast<char>(integerPart + '0');
        } else {
            decimalPlaces += static_cast<char>(integerPart - 10 + 'A');
        }
        decimalPlacesDecimal = (decimalPlacesDecimal - integerPart) * outputBase;
        decimalPlacesCount++;
    }

    // Concatenate the output string and the decimal places.
    if (!decimalPlaces.empty()) {
        outputStringReversed += '.';
        outputStringReversed += decimalPlaces;
    }

    // Set the output text.
    output->SetValue(outputStringReversed);
}

BaseConverter::BaseConverter() : wxFrame(nullptr, wxID_ANY, "Base Converter") {
    OnInit();
}

void BaseConverter::OnInit() {
    auto *inputSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *inputLabel = new wxStaticText(this, wxID_ANY, "Input:");
    inputText = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize);
    auto *inputBaseLabel = new wxStaticText(this, wxID_ANY, "Base:");
    inputBase = new wxSpinCtrl(this, wxID_ANY, "10", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 36, 10);

    inputSizer->Add(inputLabel, wxSizerFlags().Border(wxALL, 5));
    inputSizer->Add(inputText, wxSizerFlags(1).Expand().Border(wxALL, 5));
    inputSizer->Add(inputBaseLabel, wxSizerFlags().Border(wxALL, 5));
    inputSizer->Add(inputBase, wxSizerFlags().Expand().Border(wxALL, 5));

    auto *outputSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *outputLabel = new wxStaticText(this, wxID_ANY, "Output:");
    outputText = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    auto *outputBaseLabel = new wxStaticText(this, wxID_ANY, "Base:");
    outputBase = new wxSpinCtrl(this, wxID_ANY, "10", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 36, 10);

    outputSizer->Add(outputLabel, wxSizerFlags().Border(wxALL, 5));
    outputSizer->Add(outputText, wxSizerFlags(1).Expand().Border(wxALL, 5));
    outputSizer->Add(outputBaseLabel, wxSizerFlags().Border(wxALL, 5));
    outputSizer->Add(outputBase, wxSizerFlags().Expand().Border(wxALL, 5));

    auto *calculateButton = new wxButton(this, wxID_ANY, "Calculate");

    auto *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(inputSizer, wxSizerFlags(1).Expand().Border(wxRIGHT | wxLEFT, 10));
    mainSizer->Add(outputSizer, wxSizerFlags(1).Expand().Border(wxRIGHT | wxLEFT, 10));
    mainSizer->Add(calculateButton, wxSizerFlags().Expand().Border(wxALL, 10));

    SetSizerAndFit(mainSizer);

    Bind(wxEVT_BUTTON, &BaseConverter::OnUpdate, this, calculateButton->GetId());
    Bind(wxEVT_TEXT, &BaseConverter::OnUpdate, this, inputText->GetId());
    Bind(wxEVT_SPINCTRL, &BaseConverter::OnUpdate, this, inputBase->GetId());
    Bind(wxEVT_SPINCTRL, &BaseConverter::OnUpdate, this, outputBase->GetId());

    menubar.OnExit([this](wxCommandEvent &event) {
        Close(true);
    },
                   this);

    SetMenuBar(menubar.getMenubar());
}
void BaseConverter::OnUpdate(wxCommandEvent &event) {
    if (outputText && inputText && inputBase && outputBase) {
        if (inputText->IsEmpty()) {
            inputText->SetValue("0");
        }

        convertBase(inputText->GetValue().ToStdString(), inputBase->GetValue(), outputText, outputBase->GetValue());
    }
}
