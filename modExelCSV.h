//---------------------------------------------------------------------------

#ifndef modExelCSVH
#define modExelCSVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <Grids.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TExecCSV : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *ImporterFichierCSV1;
        TMenuItem *ImporterFichierTaches;
        TMenuItem *ImportCriteres;
        TMenuItem *Quitter2;
        TMenuItem *Sauvegarder1;
        TMenuItem *N1;
        TMenuItem *Quitter;
        TLabel *Label1;
        TLabel *Label10;
        TLabel *Label2;
        TLabel *Label11;
        TAdvStringGrid *ac;
        TAdvStringGrid *av;
        TLabel *Labelxx;
        TLabel *Label4;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TEdit *eSeuil;
        TLabel *Label3;
        TButton *btDel;
        TButton *btAppend;
        TButton *btIns;
        void __fastcall ImporterFichierTachesClick(
          TObject *Sender);
        void __fastcall QuitterClick(TObject *Sender);
private:	// User declarations

        char params[50][200];
        char number[20];
        bool floating;
        int TACHE;
        char LIEN[5];
        int DECAL;
        char filename[MAX_PATH];
        char filetms[MAX_PATH];
        char HomeDirectory[MAX_PATH];

        int OldCol;
        int OldRow;

        bool Change;

        char ddeb[40],dfin[40];
        int AnPrev,An;
        int MoisPrev,Mois;
        int JourPrev,Jour;
        char LastRupt[100];

        void __fastcall  SaveCriteres(char *grname);
        void __fastcall  SaveTaches(char *grname);
        void __fastcall  SaveLiaisons(char *grname);
        int  __fastcall  add_jour(int year, int month, int day, int jours);
        int  __fastcall  convert_date(int year, int month, int day);
        void __fastcall  Compute_Niveaux();
        void __fastcall  RemoveQuotes(char *pr);
        int __fastcall   ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall  SaveGrid(char *fn,TAdvStringGrid *sg) ;
        void __fastcall  LoadGrid(char *fn,TAdvStringGrid *sg);
        void __fastcall  LoadData(char *name);
        void __fastcall  Clean_Grid(TAdvStringGrid *sgrid, int strow);
        int  __fastcall  Explode(char sep,char *str);
        void __fastcall  ScanBuf(char *buf);
        int  __fastcall  Compute_NbJours(char *parm);
        void __fastcall  Compute_Succ();
        void __fastcall  Decompose(char *parm);
        void __fastcall  Deduct_Succ(int line);


public:		// User declarations
        __fastcall TExecCSV(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TExecCSV *ExecCSV;
//---------------------------------------------------------------------------
#endif
