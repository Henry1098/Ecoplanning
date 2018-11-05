//---------------------------------------------------------------------------

#ifndef modImportH
#define modImportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>

#include "FinalIsam.h"

//---------------------------------------------------------------------------
class TImport : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button1;
        TButton *Button5;
        TButton *Button6;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
        realisam *fichier;

        char ExtName[50];
        char bigbuf[100000];
        char temps[10000];
        void __fastcall Exec_Pln(char *name);
        void __fastcall Exec_Tri(char *name);
        void __fastcall Exec_Fil(char *name);
        void __fastcall Exec_Col(char *name);
        void __fastcall SelectFile();

        void __fastcall Exec_Maj_Preseance(char *name, char *Key);

public:		// User declarations
        __fastcall TImport(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImport *Import;
//---------------------------------------------------------------------------
#endif
