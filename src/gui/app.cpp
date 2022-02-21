#include "app.h"
#include <iostream>

wxIMPLEMENT_APP(GUIApp);

GUIApp::GUIApp()
{
	std::cout << "In the GUIApp constructor.\n";
}

GUIApp::~GUIApp()
{
	std::cout << "In the GUIApp destructor.\n";
}

bool GUIApp::OnInit()
{
	std::cout << "In OnInit.\n";
	this->window = new wxFrame(NULL, wxID_ANY, "LOL");
	std::cout << "Made the frame.\n";
	this->window->SetTitle("Is me");

	return true;
}