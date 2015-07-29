/***************************************************************
 * Name:      RoseStatCalcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jacob Peters ()
 * Created:   2011-08-24
 * Copyright: Jacob Peters ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "RoseStatCalcMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(RoseStatCalcFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(RoseStatCalcFrame)
const long RoseStatCalcFrame::ID_STATICBOX1 = wxNewId();
const long RoseStatCalcFrame::ID_STRSPINCTRL = wxNewId();
const long RoseStatCalcFrame::ID_DEXSPINCTRL = wxNewId();
const long RoseStatCalcFrame::ID_INTSPINCTRL = wxNewId();
const long RoseStatCalcFrame::ID_CONSPINCTRL = wxNewId();
const long RoseStatCalcFrame::ID_SENSPINCTRL = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT1 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT2 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT3 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT4 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT5 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT6 = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT7 = wxNewId();
const long RoseStatCalcFrame::ID_SPAVAILTEXT = wxNewId();
const long RoseStatCalcFrame::ID_SPUSEDTEXT = wxNewId();
const long RoseStatCalcFrame::ID_STRSPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_DEXSPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_INTSPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_CONSPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_SENSPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_STATICTEXT15 = wxNewId();
const long RoseStatCalcFrame::ID_STRRATIOTEXT = wxNewId();
const long RoseStatCalcFrame::ID_DEXRATIOTEXT = wxNewId();
const long RoseStatCalcFrame::ID_INTRATIOTEXT = wxNewId();
const long RoseStatCalcFrame::ID_CONRATIOTEXT = wxNewId();
const long RoseStatCalcFrame::ID_SENRATIOTEXT = wxNewId();
const long RoseStatCalcFrame::ID_APBOX = wxNewId();
const long RoseStatCalcFrame::ID_DEFBOX = wxNewId();
const long RoseStatCalcFrame::ID_MDEFBOX = wxNewId();
const long RoseStatCalcFrame::ID_ACCBOX = wxNewId();
const long RoseStatCalcFrame::ID_CRITBOX = wxNewId();
const long RoseStatCalcFrame::ID_DODGEBOX = wxNewId();
const long RoseStatCalcFrame::ID_APTEXT = wxNewId();
const long RoseStatCalcFrame::ID_DEFTEXT = wxNewId();
const long RoseStatCalcFrame::ID_MDEFTEXT = wxNewId();
const long RoseStatCalcFrame::ID_ACCTEXT = wxNewId();
const long RoseStatCalcFrame::ID_CRITTEXT = wxNewId();
const long RoseStatCalcFrame::ID_DODGETEXT = wxNewId();
const long RoseStatCalcFrame::ID_HPBOX = wxNewId();
const long RoseStatCalcFrame::ID_MPBOX = wxNewId();
const long RoseStatCalcFrame::ID_HPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_MPTEXT = wxNewId();
const long RoseStatCalcFrame::ID_WEPCHOICE = wxNewId();
const long RoseStatCalcFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RoseStatCalcFrame,wxFrame)
    //(*EventTable(RoseStatCalcFrame)
    //*)
END_EVENT_TABLE()

RoseStatCalcFrame::RoseStatCalcFrame(wxWindow* parent,wxWindowID id)
{
    this->character = new RoseChar;

    //(*Initialize(RoseStatCalcFrame)
    Create(parent, wxID_ANY, _("PintoPirate's Stat Calculator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(360,336));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,16), wxSize(360,320), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Box = new wxStaticBox(Panel1, ID_STATICBOX1, _("Stats"), wxPoint(16,48), wxSize(168,272), 0, _T("ID_STATICBOX1"));
    StrSpinCtrl = new wxSpinCtrl(Panel1, ID_STRSPINCTRL, _T("15"), wxPoint(48,88), wxSize(48,21), 0, 15, 400, 15, _T("ID_STRSPINCTRL"));
    StrSpinCtrl->SetValue(_T("15"));
    DexSpinCtrl = new wxSpinCtrl(Panel1, ID_DEXSPINCTRL, _T("15"), wxPoint(48,136), wxSize(48,21), 0, 15, 400, 15, _T("ID_DEXSPINCTRL"));
    DexSpinCtrl->SetValue(_T("15"));
    IntSpinCtrl = new wxSpinCtrl(Panel1, ID_INTSPINCTRL, _T("15"), wxPoint(48,184), wxSize(48,21), 0, 15, 400, 15, _T("ID_INTSPINCTRL"));
    IntSpinCtrl->SetValue(_T("15"));
    ConSpinCtrl = new wxSpinCtrl(Panel1, ID_CONSPINCTRL, _T("15"), wxPoint(48,232), wxSize(48,21), 0, 15, 400, 15, _T("ID_CONSPINCTRL"));
    ConSpinCtrl->SetValue(_T("15"));
    SenSpinCtrl = new wxSpinCtrl(Panel1, ID_SENSPINCTRL, _T("10"), wxPoint(48,280), wxSize(48,21), 0, 10, 400, 10, _T("ID_SENSPINCTRL"));
    SenSpinCtrl->SetValue(_T("10"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Str"), wxPoint(48,72), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Dex"), wxPoint(48,120), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Int"), wxPoint(48,168), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Con"), wxPoint(48,216), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Sen"), wxPoint(48,264), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("SP Used:"), wxPoint(40,32), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(8,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("SP Available:"), wxPoint(16,16), wxSize(64,13), 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(8,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    SPAvailText = new wxStaticText(Panel1, ID_SPAVAILTEXT, _("23460"), wxPoint(92,16), wxSize(36,13), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_SPAVAILTEXT"));
    SPUsedText = new wxStaticText(Panel1, ID_SPUSEDTEXT, _("0"), wxPoint(92,32), wxSize(36,13), 0, _T("ID_SPUSEDTEXT"));
    StrSPText = new wxStaticText(Panel1, ID_STRSPTEXT, _("3"), wxPoint(30,91), wxDefaultSize, 0, _T("ID_STRSPTEXT"));
    DexSPText = new wxStaticText(Panel1, ID_DEXSPTEXT, _("3"), wxPoint(32,139), wxSize(8,13), 0, _T("ID_DEXSPTEXT"));
    IntSPText = new wxStaticText(Panel1, ID_INTSPTEXT, _("3"), wxPoint(32,187), wxSize(8,13), 0, _T("ID_INTSPTEXT"));
    ConSPText = new wxStaticText(Panel1, ID_CONSPTEXT, _("3"), wxPoint(30,235), wxDefaultSize, 0, _T("ID_CONSPTEXT"));
    SenSPText = new wxStaticText(Panel1, ID_SENSPTEXT, _("2"), wxPoint(30,283), wxDefaultSize, 0, _T("ID_SENSPTEXT"));
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT15, _("AP/SP Ratio"), wxPoint(112,64), wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    StrRatioText = new wxStaticText(Panel1, ID_STRRATIOTEXT, _("0.2167"), wxPoint(120,90), wxSize(56,16), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_STRRATIOTEXT"));
    DexRatioText = new wxStaticText(Panel1, ID_DEXRATIOTEXT, _("0.08333"), wxPoint(120,138), wxSize(56,16), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_DEXRATIOTEXT"));
    IntRatioText = new wxStaticText(Panel1, ID_INTRATIOTEXT, _("Label"), wxPoint(120,186), wxSize(56,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_INTRATIOTEXT"));
    IntRatioText->Hide();
    ConRatioText = new wxStaticText(Panel1, ID_CONRATIOTEXT, _("Label"), wxPoint(120,234), wxSize(56,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_CONRATIOTEXT"));
    ConRatioText->Hide();
    SenRatioText = new wxStaticText(Panel1, ID_SENRATIOTEXT, _("0.05"), wxPoint(120,282), wxSize(56,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_SENRATIOTEXT"));
    APBox1 = new wxStaticBox(Panel1, ID_APBOX, _("Attack Power"), wxPoint(192,64), wxSize(80,40), 0, _T("ID_APBOX"));
    DefBox = new wxStaticBox(Panel1, ID_DEFBOX, _("Defense"), wxPoint(192,104), wxSize(80,40), 0, _T("ID_DEFBOX"));
    MDefBox = new wxStaticBox(Panel1, ID_MDEFBOX, _("M-Defense"), wxPoint(192,144), wxSize(80,40), 0, _T("ID_MDEFBOX"));
    AccBox = new wxStaticBox(Panel1, ID_ACCBOX, _("Accuracy"), wxPoint(192,184), wxSize(80,40), 0, _T("ID_ACCBOX"));
    CritBox = new wxStaticBox(Panel1, ID_CRITBOX, _("Critical"), wxPoint(192,224), wxSize(80,40), 0, _T("ID_CRITBOX"));
    DodgeBox = new wxStaticBox(Panel1, ID_DODGEBOX, _("Dodge"), wxPoint(192,264), wxSize(80,40), 0, _T("ID_DODGEBOX"));
    APText9 = new wxStaticText(Panel1, ID_APTEXT, _("14"), wxPoint(200,80), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_RIGHT|wxALIGN_CENTRE, _T("ID_APTEXT"));
    DefText = new wxStaticText(Panel1, ID_DEFTEXT, _("5"), wxPoint(200,120), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_DEFTEXT"));
    MDefText = new wxStaticText(Panel1, ID_MDEFTEXT, _("9"), wxPoint(200,160), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_MDEFTEXT"));
    AccText = new wxStaticText(Panel1, ID_ACCTEXT, _("18"), wxPoint(200,200), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_ACCTEXT"));
    CritText = new wxStaticText(Panel1, ID_CRITTEXT, _("13"), wxPoint(200,240), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_CRITTEXT"));
    DodgeText = new wxStaticText(Panel1, ID_DODGETEXT, _("18"), wxPoint(200,280), wxSize(64,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_DODGETEXT"));
    HPBox = new wxStaticBox(Panel1, ID_HPBOX, _("HP"), wxPoint(280,80), wxSize(72,40), 0, _T("ID_HPBOX"));
    MPBox = new wxStaticBox(Panel1, ID_MPBOX, _("MP"), wxPoint(280,128), wxSize(72,40), 0, _T("ID_MPBOX"));
    HPText = new wxStaticText(Panel1, ID_HPTEXT, _("30"), wxPoint(288,96), wxSize(56,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_HPTEXT"));
    MPText = new wxStaticText(Panel1, ID_MPTEXT, _("60"), wxPoint(288,144), wxSize(56,13), wxST_NO_AUTORESIZE|wxALIGN_CENTRE, _T("ID_MPTEXT"));
    WepChoice = new wxChoice(Panel1, ID_WEPCHOICE, wxPoint(200,16), wxSize(144,21), 0, 0, 0, wxDefaultValidator, _T("ID_WEPCHOICE"));
    WepChoice->SetSelection( WepChoice->Append(_("One-Handed Weapon")) );
    WepChoice->Append(_("Two-Handed Weapon"));
    WepChoice->Append(_("Crossbow"));
    WepChoice->Append(_("Bow"));
    WepChoice->Append(_("Katar"));
    WepChoice->Append(_("Dual Swords"));
    WepChoice->Append(_("Gun"));
    WepChoice->Append(_("Launcher"));
    WepChoice->Append(_("Magic Wand"));
    WepChoice->Append(_("Magic Staff"));

    Connect(ID_STRSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&RoseStatCalcFrame::OnStrSpinCtrlChange);
    Connect(ID_DEXSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&RoseStatCalcFrame::OnDexSpinCtrlChange);
    Connect(ID_INTSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&RoseStatCalcFrame::OnIntSpinCtrlChange);
    Connect(ID_CONSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&RoseStatCalcFrame::OnConSpinCtrlChange);
    Connect(ID_SENSPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&RoseStatCalcFrame::OnSenSpinCtrlChange);
    Connect(ID_WEPCHOICE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RoseStatCalcFrame::OnWepChoiceSelect);
    //Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RoseStatCalcFrame::OnPanel1Paint,0,this);
    //*)
}

RoseStatCalcFrame::~RoseStatCalcFrame()
{
    //(*Destroy(RoseStatCalcFrame)
    //*)
    delete this->character;
}


void RoseStatCalcFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RoseStatCalcFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


//            buf = wxString::Format("%.4g", (0.1 / floorf((float)this->character->stats.sen *0.2f)));
 //               this->SenRatioText->SetLabel(buf);
 //               this->SenRatioText->Show(TRUE);


void RoseStatCalcFrame::OnWepChoiceSelect(wxCommandEvent& event)
{
    this->character->weapon = (weapon_t)this->WepChoice->GetCurrentSelection();

    this->character->calc();

    this->updateText();
}

void RoseStatCalcFrame::OnStrSpinCtrlChange(wxSpinEvent& event)
{
    this->character->stats.str = this->StrSpinCtrl->GetValue();
    this->character->calc();
    this->updateText();
}

void RoseStatCalcFrame::OnDexSpinCtrlChange(wxSpinEvent& event)
{
    this->character->stats.dex = this->DexSpinCtrl->GetValue();
    this->character->calc();
    this->updateText();
}

void RoseStatCalcFrame::OnIntSpinCtrlChange(wxSpinEvent& event)
{
    this->character->stats.intel = this->IntSpinCtrl->GetValue();
    this->character->calc();
    this->updateText();
}

void RoseStatCalcFrame::OnConSpinCtrlChange(wxSpinEvent& event)
{
    this->character->stats.con = this->ConSpinCtrl->GetValue();
    this->character->calc();
    this->updateText();
}

void RoseStatCalcFrame::OnSenSpinCtrlChange(wxSpinEvent& event)
{
    this->character->stats.sen = this->SenSpinCtrl->GetValue();
    this->character->calc();
    this->updateText();
}

void RoseStatCalcFrame::updateText()
{
    wxString buf;
    //SP Text
    buf = wxString::Format("%d", this->character->stats.spLeft);
    if(this->character->stats.spLeft < 0)
    {
        this->SPAvailText->SetForegroundColour(wxColour("RED"));
    }
    else
    {
        this->SPAvailText->SetForegroundColour(wxColour("BLACK"));
    }
    this->SPAvailText->SetLabel(buf);

    buf = wxString::Format("%d", this->character->stats.spUsed);
    this->SPUsedText->SetLabel(buf);

    //StatSP
    buf = wxString::Format("%d", (int)floorf(((float)this->character->stats.str * 0.2f)));
    this->StrSPText->SetLabel(buf);
    buf = wxString::Format("%d", (int)floorf(((float)this->character->stats.dex * 0.2f)));
    this->DexSPText->SetLabel(buf);
    buf = wxString::Format("%d", (int)floorf(((float)this->character->stats.intel * 0.2f)));
    this->IntSPText->SetLabel(buf);
    buf = wxString::Format("%d", (int)floorf(((float)this->character->stats.con * 0.2f)));
    this->ConSPText->SetLabel(buf);
    buf = wxString::Format("%d", (int)floorf(((float)this->character->stats.sen * 0.2f)));
    this->SenSPText->SetLabel(buf);

    //Stats
    buf = wxString::Format("%d", (int)this->character->stats.ap);
    this->APText9->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.def);
    this->DefText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.mdef);
    this->MDefText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.acc);
    this->AccText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.crit);
    this->CritText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.dodge);
    this->DodgeText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.hp);
    this->HPText->SetLabel(buf);
    buf = wxString::Format("%d", (int)this->character->stats.mp);
    this->MPText->SetLabel(buf);

    switch(this->character->weapon)
    {
        case ONE_HAND:
        case TWO_HAND:
            buf = wxString::Format("%.4g", (0.65 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.25 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        case CROSS:
            buf = wxString::Format("%.4g", (0.5 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.4 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        case BOW:
            buf = wxString::Format("%.4g", (0.6 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.3 / floorf((float)this->character->stats.con *0.2f)));

                this->ConRatioText->SetLabel(buf);
                this->ConRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->StrRatioText->Hide();
            break;

        case KATAR:
            buf = wxString::Format("%.4g", (0.35 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.55 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        case DUAL:
            buf = wxString::Format("%.4g", (0.55 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.35 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        case GUN:
            buf = wxString::Format("%.4g", (0.4 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.5 / floorf((float)this->character->stats.con *0.2f)));

                this->ConRatioText->SetLabel(buf);
                this->ConRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->StrRatioText->Hide();
            break;

        case LAUNCHER:
            buf = wxString::Format("%.4g", (0.35 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.55 / floorf((float)this->character->stats.con *0.2f)));

                this->ConRatioText->SetLabel(buf);
                this->ConRatioText->Show(TRUE);
            this->IntRatioText->Hide();
            this->DexRatioText->Hide();
            break;

        case WAND:
            buf = wxString::Format("%.4g", (0.35 / floorf((float)this->character->stats.dex *0.2f)));

                this->DexRatioText->SetLabel(buf);
                this->DexRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.55 / floorf((float)this->character->stats.intel *0.2f)));

                this->IntRatioText->SetLabel(buf);
                this->IntRatioText->Show(TRUE);
            this->StrRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        case STAFF:
            buf = wxString::Format("%.4g", (0.3 / floorf((float)this->character->stats.str *0.2f)));

                this->StrRatioText->SetLabel(buf);
                this->StrRatioText->Show(TRUE);
            buf = wxString::Format("%.4g", (0.6 / floorf((float)this->character->stats.intel *0.2f)));

                this->IntRatioText->SetLabel(buf);
                this->IntRatioText->Show(TRUE);
            this->DexRatioText->Hide();
            this->ConRatioText->Hide();
            break;

        default:
            break;
    }

    buf = wxString::Format("%.4g", (0.1 / floorf((float)this->character->stats.sen *0.2f)));
    this->SenRatioText->SetLabel(buf);
}
