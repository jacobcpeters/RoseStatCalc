/***************************************************************
 * Name:      RoseStatCalcApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jacob Peters ()
 * Created:   2011-08-24
 * Copyright: Jacob Peters ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "RoseStatCalcApp.h"

//(*AppHeaders
#include "RoseStatCalcMain.h"
#include <wx/image.h>
//*)



IMPLEMENT_APP(RoseStatCalcApp);

bool RoseStatCalcApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	RoseStatCalcFrame* Frame = new RoseStatCalcFrame(0);
    	Frame->SetIcons(wxIconBundle(wxIcon("main_icon")));
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
