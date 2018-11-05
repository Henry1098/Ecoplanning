//---------------------------------------------------------------------------

#ifndef modLignesBriseesH
#define modLignesBriseesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Dialogs.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TLBrisee : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TAdvStringGrid *AAdvLB;
        TLabel *Label4;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TColorDialog *ColorDialog1;
        TLabel *Label3;
        void __fastcall AAdvLBClickCell(TObject *Sender, int ARow,
          int ACol);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall AAdvLBGetEditorType(TObject *Sender, int ACol,
          int ARow, TEditorType &AEditor);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        char params[50][100];

        int __fastcall Explode(char sep,char *str);
        float __fastcall atoxx(char *tout);
public:		// User declarations
        __fastcall TLBrisee(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLBrisee *LBrisee;
//---------------------------------------------------------------------------
#endif
