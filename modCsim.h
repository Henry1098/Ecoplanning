//---------------------------------------------------------------------------

#ifndef modCsimH
#define modCsimH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <stdio.h>
#include <Dialogs.hpp> 
#include <string>
//---------------------------------------------------------------------------
class TSimulOpen : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TRadioButton *rbDates;
        TRadioButton *rbTaches;
        TEdit *eCrit;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *eNombre;
        TAdvStringGrid *avsim;
        TButton *btSave;
        TButton *Button3;
        TButton *Button4;
        TLabel *Label5;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TMonthCalendar *MonthCalendar1;
        TButton *btCreer;
        TButton *Button10;
        TLabel *Label12;
        TButton *Button12;
        TBevel *Bevel2;
        TButton *btLancer;
        TSaveDialog *SaveDialog1;
        TLabel *lName;
        TLabel *Label15;
        TLabel *Label16;
        TEdit *eTaches;
        TButton *btSuppr;
        TButton *btSavSimul;
        TAdvStringGrid *avbis;
        TMemo *mComment;
        TBevel *Bevel1;
        TBevel *Bevel3;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label2;
        TOpenDialog *OpenDialog1;
        void __fastcall btCreerClick(TObject *Sender);
        void __fastcall avsimClickCell(TObject *Sender, int ARow,
          int ACol);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall btSaveClick(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall avsimCanEditCell(TObject *Sender, int ARow,
          int ACol, bool &CanEdit);
        void __fastcall avsimCellValidate(TObject *Sender, int ACol,
          int ARow, AnsiString &Value, bool &Valid);
        void __fastcall btSupprClick(TObject *Sender);
        void __fastcall btLancerClick(TObject *Sender);
        void __fastcall rbDatesClick(TObject *Sender);
        void __fastcall rbTachesClick(TObject *Sender);
        void __fastcall avsimGetFormat(TObject *Sender, int ACol,
          TSortStyle &AStyle, AnsiString &aPrefix, AnsiString &aSuffix);
        void __fastcall MonthCalendar1DblClick(TObject *Sender);
        void __fastcall eNombreChange(TObject *Sender);
        void __fastcall eTachesChange(TObject *Sender);
        void __fastcall eTachesClick(TObject *Sender);
        void __fastcall eNombreClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations



char  CurrentSim[MAX_PATH];

AnsiString MemCell;
int   Cnt;
int   nbrow;
int   OldCol,OldRow;
char  Crit[100];
char  name[MAX_PATH];
int   An,Mois,Jour;
AnsiString memoCrit,memoTaches,memoDates;

int NB1,NB2,NB3;

bool loaded;

char params[200][50];

void __fastcall Clean_Grid(TAdvStringGrid *sgrid, int strow);
int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
void __fastcall Extraire_Data();
//void __fastcall Select_Criteres(char *crit);
void __fastcall Simule(int row,int col);
void __fastcall Simule_Taches(int row,int col);
int  __fastcall add_jour(int year, int month, int day, int jours);
 void __fastcall Renum();
int  __fastcall convert_date(char *dat);
void __fastcall Select_Dates(AnsiString dat);
void __fastcall Select_Taches(AnsiString dat);
int __fastcall  Explode(char sep,char *str);
int __fastcall  Find_Task(int nt);
int  __fastcall recule_conges(int base,int ncal);
int  __fastcall recule_temps(int base,int ncal,int dur);
int  __fastcall avance_conges(int base,int ncal);
int  __fastcall avance_temps(int base,int ncal,int dur);
int  __fastcall nbjt(int d1, int d2);
void __fastcall Process_Dates();
int  __fastcall Compute_Duree(AnsiString deb,AnsiString end);
void __fastcall Fill_AvSort(int col);
int  __fastcall comp_dist_dates(char *dt1, char *dt2, int calx,int offset);


public:		// User declarations
        __fastcall TSimulOpen(TComponent* Owner);
        void __fastcall sortDayMonthYear();
};
//---------------------------------------------------------------------------
extern PACKAGE TSimulOpen *SimulOpen;
//---------------------------------------------------------------------------
#endif
