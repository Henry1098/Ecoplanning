//---------------------------------------------------------------------------

#ifndef actualisationH
#define actualisationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TActual : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TListBox *ListBox1;
        TMonthCalendar *MonthCalendar1;
        TLabel *Label2;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TEdit *eFile;
        TLabel *Label3;
        TButton *Button4;
        TButton *btEff;
        TButton *Button5;
        void __fastcall MonthCalendar1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall btEffClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
private:	// User declarations

#define MAX_PARAMS 30
 //       char exchange[2000];
 //       char exchange2[2000];
        char ecoplan[50];
        char params[MAX_PARAMS][50];
        char txt[250];
        char localbase[250];
        // char Suffixe[10];
        bool newfile;
        int nlast;
        char DatAct[50];
        char lastsuffix[250];
        AnsiString FileSelected;
        // char lastfile[250];

        int  NB_ACT;
        int distprev;
        int  DISTLAST;

        bool FIRST;

        void __fastcall Exec_Finish();
        int  __fastcall ExplodeX(char sep,char *str);
        void __fastcall FillListBox();
//        void __fastcall ReadExchange(int n);
//        void __fastcall WriteExchange(int n);

public:		// User declarations
        __fastcall TActual(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TActual *Actual;
//---------------------------------------------------------------------------
#endif
