//
// Created by Matthew McCall on 11/9/22.
//

#include "KeypadButton.hpp"

BEGIN_EVENT_TABLE(KeypadButton, wxPanel)

EVT_LEFT_DOWN(KeypadButton::mouseDown)
EVT_LEFT_UP(KeypadButton::mouseReleased)
EVT_MOTION(KeypadButton::mouseMoved)
EVT_LEAVE_WINDOW(KeypadButton::mouseLeftWindow)

// catch paint events
EVT_PAINT(KeypadButton::paintEvent)

END_EVENT_TABLE()

KeypadButton::KeypadButton(wxFrame *parent, wxWindowID id, wxString text) : wxWindow(parent, id), text(text), pressedDown(false), hovered(false) {
    Init();
}

void KeypadButton::paintEvent(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    render(dc);
}

void KeypadButton::paintNow() {
    wxClientDC dc(this);
    render(dc);
}

void KeypadButton::render(wxDC &dc) {

    dc.SetPen(wxPen(wxColour(0, 0, 0, 64)));

    if (pressedDown)
        dc.SetBrush(*wxGREY_BRUSH);
    else if (hovered)
        dc.SetBrush(*wxLIGHT_GREY_BRUSH);
    else
        dc.SetBrush(wxBrush(wxColour(250, 250, 250, 64)));

    wxSize dcSize = dc.GetSize();
    dc.DrawRoundedRectangle(0, 0, std::max(MIN_BUTTON_WIDTH, dcSize.GetWidth()), std::max(MIN_BUTTON_HEIGHT, dcSize.GetHeight()), 4);

    wxSize textSize = dc.GetTextExtent(text);
    dc.DrawText(text, (dcSize.GetWidth() - textSize.GetWidth()) / 2, (dcSize.GetHeight() - textSize.GetHeight()) / 2);
}

void KeypadButton::mouseDown(wxMouseEvent &event) {
    pressedDown = true;
    paintNow();
}

void KeypadButton::mouseReleased(wxMouseEvent &event) {
    pressedDown = false;
    paintNow();

    // wxMessageBox(wxT("You pressed a custom button"));
}

void KeypadButton::mouseLeftWindow(wxMouseEvent &event) {
    pressedDown = false;
    hovered = false;
    paintNow();
}
void KeypadButton::Init() {
    SetMinSize(wxSize(MIN_BUTTON_WIDTH, MIN_BUTTON_HEIGHT));
}

void KeypadButton::mouseMoved(wxMouseEvent &event) {
    hovered = true;
    paintNow();
}
