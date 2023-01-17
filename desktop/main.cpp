#include "views/SimpleView.hpp"

class OasisDesktop : public wxApp {
public:
    bool OnInit() override {
        auto *menuFile = new wxMenu;
        menuFile->Append(wxID_EXIT);

        auto *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);

        menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");

        Bind(wxEVT_MENU, &OasisDesktop::OnAbout, this, wxID_ABOUT);
        Bind(wxEVT_MENU, &OasisDesktop::OnExit, this, wxID_EXIT);

        simpleView = new SimpleView();
        simpleView->SetMenuBar(menuBar);
        simpleView->Show(true);

        return true;
    }

    void OnExit(wxCommandEvent &event) {
        simpleView->Close(true);
    }

    void OnAbout(wxCommandEvent &event) {
        wxMessageBox("Copyright © 2022 Matthew McCall and Andrew Nazareth",
                     "About Oasis Desktop", wxOK | wxICON_INFORMATION);
    }

private:
    wxMenuBar *menuBar;
    SimpleView *simpleView;
};

wxIMPLEMENT_APP(OasisDesktop);