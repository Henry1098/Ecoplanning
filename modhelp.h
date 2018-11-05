//---------------------------------------------------------------------------

#ifndef modhelpH
#define modhelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//#include "Word_97_SRVR.h"
#include <OleServer.hpp>
//---------------------------------------------------------------------------
class Thelp : public TForm
{
__published:	// IDE-managed Components
        TCppWebBrowser *CppWebBrowser1;
        TButton *Button1;
        TBevel *Bevel1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TComboBox *URLCombo;
        TButton *btIndex;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall btIndexClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Thelp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thelp *help;
//---------------------------------------------------------------------------
#endif
