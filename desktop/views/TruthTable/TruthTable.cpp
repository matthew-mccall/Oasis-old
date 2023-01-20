//
// Created by Matthew McCall on 1/17/23.
//

#include "TruthTable.hpp"

TruthTable::TruthTable() {
    OnInit();
}

void TruthTable::OnInit() {
    table = new wxGrid(this, wxID_ANY);
    table->CreateGrid(2, 2);

    auto *verticalSizer = new wxBoxSizer(wxVERTICAL);
    verticalSizer->Add(table, 1, wxEXPAND);

    auto *horizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *addVariableButton = new wxButton(this, wxID_ANY, "Add Variable");
    auto *addConditionButton = new wxButton(this, wxID_ANY, "Add Condition");
    auto *removeVariableButton = new wxButton(this, wxID_ANY, "Remove Variable");
    auto *removeConditionButton = new wxButton(this, wxID_ANY, "Remove Condition");
    horizontalSizer->Add(addVariableButton, 0, wxEXPAND);
    horizontalSizer->Add(removeVariableButton, 0, wxEXPAND);
    horizontalSizer->Add(addConditionButton, 0, wxEXPAND);
    horizontalSizer->Add(removeConditionButton, 0, wxEXPAND);

    verticalSizer->Add(horizontalSizer, 0, wxEXPAND);
}
