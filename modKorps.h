//---------------------------------------------------------------------------

#ifndef modKorpsH
#define modKorpsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFDKorps : public TForm
{
__published:	// IDE-managed Components
        TImage *imFColor;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TBevel *Bevel1;
        TImage *Image1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TAdvStringGrid *avl;
        TAdvStringGrid *avv;
        TColorDialog *ColorDialog1;

        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall avvClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall avvCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);

private:	// User declarations

        void __fastcall FillColor(int color,TImage *im);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
public:		// User declarations
        __fastcall TFDKorps(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDKorps *FDKorps;
//---------------------------------------------------------------------------
#endif
