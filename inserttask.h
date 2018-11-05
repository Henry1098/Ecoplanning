//---------------------------------------------------------------------------

#ifndef inserttaskH
#define inserttaskH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <stdio.h>

//---------------------------------------------------------------------------
class TNewTask : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label4;
        TEdit *Edit3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TNewTask(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewTask *NewTask;

//---------------------------------------------------------------------------
#endif
