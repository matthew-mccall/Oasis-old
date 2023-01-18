#include "views/Arithmetic/Arithmetic.hpp"

class OasisDesktop : public wxApp {
public:
    bool OnInit() override {

        arithmetic = new Arithmetic();
        arithmetic->Show(true);

        return true;
    }

private:
    Arithmetic *arithmetic {};
};

wxIMPLEMENT_APP(OasisDesktop);