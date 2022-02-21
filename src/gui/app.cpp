#include "app.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(GUIApp);

GUIApp::GUIApp()
{

}

GUIApp::~GUIApp()
{

}

bool GUIApp::OnInit()
{
	wxFrame mainFrame {NULL, wxID_ANY, "LOL"};
	mainFrame.Show();
	
	return true;
}