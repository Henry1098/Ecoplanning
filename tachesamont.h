//---------------------------------------------------------------------------

#ifndef tachesamontH
#define tachesamontH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfTachesAmont : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TCheckBox *CheckBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label4;
        TLabel *Label5;
        TBevel *Bevel1;
        TUpDown *UpDown1;
        TUpDown *UpDown2;
        TLabel *Label6;
        TAdvStringGrid *asAmont;
        TLabel *Label3;
        TEdit *Edit3;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
        char ecoplan[50];
        int  tache_mere;
public:		// User declarations
        __fastcall TfTachesAmont(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfTachesAmont *fTachesAmont;
//---------------------------------------------------------------------------
#endif
