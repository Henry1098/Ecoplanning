//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "modhelp.h"
#include "globals.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
// #pragma link "Word_97_SRVR"
#pragma resource "*.dfm"
Thelp *help;
//---------------------------------------------------------------------------
__fastcall Thelp::Thelp(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Thelp::FormCreate(TObject *Sender)
{
 AnsiString Start;

// CppWebBrowser1->Navigate((WideString)"http://www.cnn.com");
// CppWebBrowser1->Navigate((WideString)"http://www.lemonde.fr");
// CppWebBrowser1->Navigate((WideString)"c:\\mes documents\\index.htm");
   //  necessaire de specifier le repertoire complet

 Start = AnsiString(HelpDirectory)+ AnsiString(m_help);
 CppWebBrowser1->Navigate((WideString)Start);
 //  CppWebBrowser1->Navigate((WideString)"c:\\ecoplanning-aide\\index.htm");

}
//---------------------------------------------------------------------------
void __fastcall Thelp::Button1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall Thelp::FormClose(TObject *Sender, TCloseAction &Action)
{
 Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall Thelp::Button4Click(TObject *Sender)
{
 CppWebBrowser1->Navigate(WideString(URLCombo->Text));
}
//---------------------------------------------------------------------------
void __fastcall Thelp::Button2Click(TObject *Sender)
{
CppWebBrowser1->GoBack();
}
//---------------------------------------------------------------------------
void __fastcall Thelp::Button3Click(TObject *Sender)
{
CppWebBrowser1->GoForward();
}
//---------------------------------------------------------------------------

void __fastcall Thelp::Button6Click(TObject *Sender)
{
CppWebBrowser1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall Thelp::Button5Click(TObject *Sender)
{
CppWebBrowser1->Stop();
}
//---------------------------------------------------------------------------
void __fastcall Thelp::btIndexClick(TObject *Sender)
{
 AnsiString Home;
 char index[MAX_PATH];

 strcpy(index,m_directory);
 strcat(index,"\\Help\\sommaire.html");
 Home = AnsiString(index);
 CppWebBrowser1->Navigate((WideString)Home);
}
//---------------------------------------------------------------------------

