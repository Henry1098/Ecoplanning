//---------------------------------------------------------------------------

#ifndef modDcalH
#define modDcalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFDcal : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *avh;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TImage *imFColor;
        TImage *imBColor;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall avhClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall avhCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations

int OldCol,OldRow;

         void __fastcall FillColor(int color,TImage *im);
         int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
public:		// User declarations
        __fastcall TFDcal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDcal *FDcal;
//---------------------------------------------------------------------------
#endif
