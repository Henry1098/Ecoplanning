//---------------------------------------------------------------------------

#ifndef modEnteteH
#define modEnteteH
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
class TEntete : public TForm
{
__published:	// IDE-managed Components
        TAdvStringGrid *avl;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TLabel *Label1;
        TEdit *Edit1;
        TButton *btBackGround;
        TImage *imFColor;
        TLabel *Label2;
        TImage *imBColor;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *eLogo;
        TLabel *Label9;
        TButton *Button4;
        TImage *iLogo;
        TOpenDialog *OpenDialog1;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall avlClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall btBackGroundClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall avlCanEditCell(TObject *Sender, int ARow, int ACol,
          bool &CanEdit);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations

        int OldCol,OldRow;


        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall FillData(int ind);
        void __fastcall FillGrid(int ind);
        void __fastcall FillColor(int color,TImage *im);

public:		// User declarations
        __fastcall TEntete(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEntete *Entete;
//---------------------------------------------------------------------------
#endif
