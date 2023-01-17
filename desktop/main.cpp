#include "views/SimpleView.hpp"

class OasisDesktop : public wxApp {
public:
    bool OnInit() override {
        auto *simpleView = new SimpleView();
        simpleView->Show(true);
        return true;
    }

    int OnExit() override {
        return wxAppBase::OnExit();
    }
};

wxIMPLEMENT_APP(OasisDesktop);