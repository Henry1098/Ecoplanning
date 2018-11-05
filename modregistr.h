//---------------------------------------------------------------------------

#ifndef modregistrH
#define modregistrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <nb30.h>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TRegist : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *edLK;
        TButton *Button1;
        TEdit *edMAC;
        TButton *Button2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations

        int LENCODE;
        char INPUT[256];
        char OUTPUT[256];
        char RESULT[256];
        AnsiString mac_addr;
        char MAC_ADDR[50];
        char LK[500];
        char EXPDATE[20];



        void __fastcall Enum_MAC();
         bool __fastcall GetAdapterInfo(int adapter_num, AnsiString &mac_addr);
         void __fastcall EncodeHexa(char *inp, char *out);
         void __fastcall DecodeHexa(char *inp, char *out);

         void __fastcall EncodeData(char *inp,char *outp);
         void __fastcall DecodeData(char *result,char *inp);
         int __fastcall  ExtractValue(char *result, char *buff, char *tag, int posdeb);

public:		// User declarations
        __fastcall TRegist(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegist *Regist;
//---------------------------------------------------------------------------
#endif
