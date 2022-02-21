#include "src/app/gui.h"
#include <iostream>

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
	wxFrame* mainFrame = new wxFrame(NULL, wxID_ANY, "LOL");
	std::cout << "Made the frame.\n";
	mainFrame->SetTitle("Is me");

	auto thing = mainFrame->Show();

	if (!thing) {
		std::cout << "THing returned true";

	}
	std::cout << "Showing the frame.\n";

	while (true) {
		std::cout << "Printing forever.\n";
		// Infinite loop.
	}

	return true;
}

wxIMPLEMENT_APP(GUIApp);
