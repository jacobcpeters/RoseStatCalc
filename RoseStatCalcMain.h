/***************************************************************
 * Name:      RoseStatCalcMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jacob Peters ()
 * Created:   2011-08-24
 * Copyright: Jacob Peters ()
 * License:
 **************************************************************/

#ifndef ROSESTATCALCMAIN_H
#define ROSESTATCALCMAIN_H

//(*Headers(RoseStatCalcFrame)
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/frame.h>
//*)

#include "classes.h"

class RoseStatCalcFrame: public wxFrame
{
    public:

        RoseChar *character;

        void updateText();

        RoseStatCalcFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~RoseStatCalcFrame();

    private:

        //(*Handlers(RoseStatCalcFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSpinButton1Change(wxSpinEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnWepComboBoxSelect(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnWepChoiceSelect(wxCommandEvent& event);
        void OnStrSpinCtrlChange(wxSpinEvent& event);
        void OnDexSpinCtrlChange(wxSpinEvent& event);
        void OnIntSpinCtrlChange(wxSpinEvent& event);
        void OnConSpinCtrlChange(wxSpinEvent& event);
        void OnSenSpinCtrlChange(wxSpinEvent& event);
        //*)

        //(*Identifiers(RoseStatCalcFrame)
        static const long ID_STATICBOX1;
        static const long ID_STRSPINCTRL;
        static const long ID_DEXSPINCTRL;
        static const long ID_INTSPINCTRL;
        static const long ID_CONSPINCTRL;
        static const long ID_SENSPINCTRL;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_SPAVAILTEXT;
        static const long ID_SPUSEDTEXT;
        static const long ID_STRSPTEXT;
        static const long ID_DEXSPTEXT;
        static const long ID_INTSPTEXT;
        static const long ID_CONSPTEXT;
        static const long ID_SENSPTEXT;
        static const long ID_STATICTEXT15;
        static const long ID_STRRATIOTEXT;
        static const long ID_DEXRATIOTEXT;
        static const long ID_INTRATIOTEXT;
        static const long ID_CONRATIOTEXT;
        static const long ID_SENRATIOTEXT;
        static const long ID_APBOX;
        static const long ID_DEFBOX;
        static const long ID_MDEFBOX;
        static const long ID_ACCBOX;
        static const long ID_CRITBOX;
        static const long ID_DODGEBOX;
        static const long ID_APTEXT;
        static const long ID_DEFTEXT;
        static const long ID_MDEFTEXT;
        static const long ID_ACCTEXT;
        static const long ID_CRITTEXT;
        static const long ID_DODGETEXT;
        static const long ID_HPBOX;
        static const long ID_MPBOX;
        static const long ID_HPTEXT;
        static const long ID_MPTEXT;
        static const long ID_WEPCHOICE;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(RoseStatCalcFrame)
        wxStaticText* DexSPText;
        wxSpinCtrl* ConSpinCtrl;
        wxStaticText* AccText;
        wxStaticText* DexRatioText;
        wxStaticText* MDefText;
        wxSpinCtrl* DexSpinCtrl;
        wxStaticText* StaticText2;
        wxStaticBox* DodgeBox;
        wxStaticText* SPAvailText;
        wxStaticText* MPText;
        wxStaticText* StaticText6;
        wxStaticBox* DefBox;
        wxStaticText* SenRatioText;
        wxStaticBox* Box;
        wxSpinCtrl* IntSpinCtrl;
        wxChoice* WepChoice;
        wxStaticText* StaticText8;
        wxStaticText* HPText;
        wxPanel* Panel1;
        wxStaticText* ConSPText;
        wxStaticText* StaticText1;
        wxSpinCtrl* SenSpinCtrl;
        wxSpinCtrl* StrSpinCtrl;
        wxStaticText* StaticText3;
        wxStaticBox* CritBox;
        wxStaticBox* AccBox;
        wxStaticText* IntRatioText;
        wxStaticText* DefText;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStaticText* DodgeText;
        wxStaticText* StrSPText;
        wxStaticBox* HPBox;
        wxStaticText* ConRatioText;
        wxStaticText* SenSPText;
        wxStaticText* APText9;
        wxStaticBox* APBox1;
        wxStaticBox* MPBox;
        wxStaticText* CritText;
        wxStaticText* SPUsedText;
        wxStaticBox* MDefBox;
        wxStaticText* StaticText4;
        wxStaticText* IntSPText;
        wxStaticText* StrRatioText;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ROSESTATCALCMAIN_H
