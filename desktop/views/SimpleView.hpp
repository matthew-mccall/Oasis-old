//
// Created by Matthew McCall on 11/9/22.
//

#ifndef OASIS_SIMPLEVIEW_HPP
#define OASIS_SIMPLEVIEW_HPP


class SimpleView : public wxFrame {
public:
    SimpleView();

private:
    void OnInit();
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    wxMenuBar *menuBar = nullptr;
};


#endif//OASIS_SIMPLEVIEW_HPP
