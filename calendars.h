//---------------------------------------------------------------------------

#ifndef calendarsH
#define calendarsH


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>

#include "FinalIsam.h"

//---------------------------------------------------------------------------
class TfCalendar : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TListBox *lbCal;
        TGroupBox *GroupBox1;
        TCheckBox *cb1;
        TCheckBox *cb2;
        TCheckBox *cb3;
        TCheckBox *cb4;
        TCheckBox *cb5;
        TCheckBox *cb6;
        TCheckBox *cb7;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TLabel *lMonth;
        TComboBox *ComboBox1;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label2;
        TMemo *mComment;
        TButton *btAide;
        TButton *Button4;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall lbCalDblClick(TObject *Sender);
        void __fastcall ComboBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall btAideClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);

private:	// User declarations
        Word  Year,Month,Day;
        realisam *cals;
        char   cal_name[50];
        char   cal_title[255];
        char   c[32];
        char   w[30];
        int    m_changed;   // changement dans le mois
        int    w_changed;   // changement dans le wend

        int    num_cal;

        void __fastcall DisplayCalendar(Word Year,Word Month, Word Day,int numc);
        void __fastcall InitCalendar();
        void __fastcall update_we();
        int __fastcall ExtractValue(char *result, char *buff, char *tag,int posdeb);

public:		// User declarations
        __fastcall TfCalendar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfCalendar *fCalendar;
//---------------------------------------------------------------------------
#endif
