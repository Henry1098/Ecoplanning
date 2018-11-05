//---------------------------------------------------------------------------

#ifndef modCorpsH
#define modCorpsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFDcorps : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TImage *imFColor;
        TAdvStringGrid *avl;
        TAdvStringGrid *avv;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TBevel *Bevel1;
        TColorDialog *ColorDialog1;
        TImage *Image1;
        TCheckBox *cbForce;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall avvClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall avvCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall avvCellsChanged(TObject *Sender, TRect &R);
        void __fastcall avvCanEditCell(TObject *Sender, int ARow, int ACol,
          bool &CanEdit);
private:	// User declarations


        void __fastcall FillColor(int color,TImage *im);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TFDcorps(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDcorps *FDcorps;
//---------------------------------------------------------------------------
#endif
