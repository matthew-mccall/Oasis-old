#include "views/SimpleView/SimpleView.hpp"

class OasisDesktop : public wxApp {
public:
    bool OnInit() override {
        simpleView = new SimpleView();
        simpleView->Show(true);

        return true;
    }

private:
    SimpleView *simpleView {};
};

wxIMPLEMENT_APP(OasisDesktop);