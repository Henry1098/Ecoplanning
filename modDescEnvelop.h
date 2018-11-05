//---------------------------------------------------------------------------

#ifndef modDescEnvelopH
#define modDescEnvelopH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TDescEnvelop : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *btOK;
        TButton *btCancel;
        TButton *btAide;
        TImage *Image1;
        TColorDialog *ColorDialog1;
        TEdit *Edit1;
        TEdit *Edit2;
        TAdvStringGrid *avl;
        TLabel *Label4;
        TImage *Image2;
        TCheckBox *cb1;
        TCheckBox *cb2;
        TLabel *Label5;
        TImage *Image3;
        TFontDialog *FontDialog1;
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall btCancelClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btOKClick(TObject *Sender);
        void __fastcall Edit1Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btAideClick(TObject *Sender);
private:	// User declarations
        TColor coultrait;
        TColor coulbackg;
        TColor coultext;

   void __fastcall FillColor(int color,TImage *im);



public:		// User declarations
        __fastcall TDescEnvelop(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDescEnvelop *DescEnvelop;
//---------------------------------------------------------------------------
#endif
