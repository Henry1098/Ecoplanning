//---------------------------------------------------------------------------

#ifndef modPreviewH
#define modPreviewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TPreview : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *Button1;
        TImage *imP1p;
        TImage *imP1l;
        TTrackBar *ZoomP1;
        TLabel *Label1;
        TLabel *Label2;
        TMemo *Memo1;
        TLabel *Label3;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        
        void __fastcall imP1pMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ZoomP1Change(TObject *Sender);
        void __fastcall imP1lMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
        int rx1,rx2,ry1,ry2;
        int OlpPos;
        int MODE;
        int OldXP1P,OldYP1P;
        int OldXP1L,OldYP1L;

        TImage  *Vim;
        char     orientation[20];
        void __fastcall Draw_Cadre(TImage *img,int epaiss,TColor cool);
        int __fastcall ExtractValue(char *result, char *buff, char *tag, int posdeb);
        void __fastcall ZoomCopy1(TImage *i,int X,int Y);

public:		// User declarations
        __fastcall TPreview(TComponent* Owner);
        int modelc;
};
//---------------------------------------------------------------------------
extern PACKAGE TPreview *Preview;
//---------------------------------------------------------------------------
#endif
