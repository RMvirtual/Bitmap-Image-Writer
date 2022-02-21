#pragma once

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class GUIApp : public wxApp
{
public:
	GUIApp();
	~GUIApp();

	virtual bool OnInit() override;
};