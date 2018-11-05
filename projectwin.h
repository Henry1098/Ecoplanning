//---------------------------------------------------------------------------

#ifndef projectwinH
#define projectwinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "FinalIsam.h"
#include "plstd.h"

#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfProjet : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *ENomProj;
        TLabel *Label5;
        TEdit *eTitre;
        TButton *btHelp;
        TButton *btSaveCont;
        TLabel *Label9;
        TEdit *eDebPrev;
        TButton *Button1;
        TDirectoryListBox *DirectoryListBox1;
        TLabel *Label2;
        TDriveComboBox *DriveComboBox1;
        TLabel *Label3;
        TLabel *Label4;
        TMemo *Memo1;
        TLabel *Label6;
        TButton *btImport;
        TOpenDialog *OpenDialog1;
        TMonthCalendar *MonthCalendar1;
        TButton *Button2;
        void __fastcall btSaveContClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall MonthCalendar1Click(TObject *Sender);
        void __fastcall DirectoryListBox1Click(TObject *Sender);
        void __fastcall DriveComboBox1Change(TObject *Sender);
        void __fastcall btImportClick(TObject *Sender);
        void __fastcall btHelpClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ENomProjExit(TObject *Sender);
private:	// User declarations
        //Word Year, Month, Day;
        realisam *newproj;
        AnsiString Directory;

        int    ModeImport;



        bool __fastcall Control_ValidField(char *fld,char *txt);
        int __fastcall SaveProject();
public:		// User declarations
        __fastcall TfProjet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfProjet *fProjet;
extern char *DatabaseName;
extern realisam *db;
extern int Cancel;

//---------------------------------------------------------------------------
#endif
