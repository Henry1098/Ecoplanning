//---------------------------------------------------------------------------

#ifndef modplanchesH
#define modplanchesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <ComCtrls.hpp>
#include <Grids.hpp>

//---------------------------------------------------------------------------
class TPlanches : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TAdvStringGrid *AdvF;
        TButton *btNewField;
        TLabel *Label24;
        TButton *btSaveFields;
        TButton *btEraseField;
        TAdvStringGrid *AdvV;
        TLabel *Label23;
        TButton *Button2;
        TButton *Button4;
        TAdvStringGrid *AdvSGVolet;
        TLabel *Label25;
        TButton *Button6;
        TAdvStringGrid *AdvP;
        TListBox *lbPlanches;
        TEdit *ePlanches;
        TButton *btPlanches;
        TLabel *Label1;
        TLabel *Label2;
        TListBox *ListBox1;
        TLabel *Label3;
        TButton *btSave;
        TButton *Button1;
        TButton *Button3;
        TLabel *Label4;
        TButton *Button5;
        TButton *Button7;
        void __fastcall btNewFieldClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btSaveClick(TObject *Sender);
        void __fastcall btSaveFieldsClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall AdvVClickCell(TObject *Sender, int ARow, int ACol);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations

        char main_directory[MAX_PATH];
        char localbase[MAX_PATH];
        char vfilename[255];
        int  fnumber;
        int  vnumber;
        int  pnumber;
        char buffer[5000];
        int change;


        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        int __fastcall SaveData();
public:		// User declarations
        __fastcall TPlanches(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPlanches *Planches;
//---------------------------------------------------------------------------
#endif
