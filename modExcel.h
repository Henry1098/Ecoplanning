//---------------------------------------------------------------------------

#ifndef modExcelH
#define modExcelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Excel_97_SRVR.h"
//#include <OleCtnrs.hpp>
#include <OleServer.hpp>


#include <sysvari.h>
#include <OleCtnrs.hpp>
//---------------------------------------------------------------------------
class TFExcel : public TForm
{
__published:	// IDE-managed Components
        TExcelApplication *xlsApp;
        TExcelWorkbook *xlsWB;
        TExcelWorksheet *xlsWS;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFExcel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFExcel *FExcel;
//---------------------------------------------------------------------------
#endif
