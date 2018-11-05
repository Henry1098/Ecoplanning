//---------------------------------------------------------------------------

#ifndef modDebutH
#define modDebutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TDateProjet : public TForm
{
__published:	// IDE-managed Components
        TMonthCalendar *MonthCalendar1;
        TEdit *eDebPrev;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall MonthCalendar1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDateProjet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDateProjet *DateProjet;
//---------------------------------------------------------------------------
#endif
