#ifndef AdvObjHPP 
#define AdvObjHPP 
 
#pragma delphiheader begin 
#pragma option push -w- 
#pragma option push -Vx 
#include <SysUtils.hpp>	// Pascal unit 
#include <Messages.hpp>	// Pascal unit 
#include <Classes.hpp>	// Pascal unit 
#include <Dialogs.hpp>	// Pascal unit 
#include <ExtCtrls.hpp>	// Pascal unit 
#include <Graphics.hpp>	// Pascal unit 
#include <Controls.hpp>	// Pascal unit 
#include <StdCtrls.hpp>	// Pascal unit 
#include <Windows.hpp>	// Pascal unit 
#include <SysInit.hpp>	// Pascal unit 
#include <System.hpp>	// Pascal unit 
 
//-- user supplied ----------------------------------------------------------- 
 
namespace Advobj 
{ 
//-- type declarations ------------------------------------------------------- 
#pragma option push -b- 
enum TArrowDirection { arrUp, arrDown, arrLeft, arrRight }; 
#pragma option pop 
 
typedef void __fastcall (__closure *TImageChangeEvent)(System::TObject* Sender, int Acol, int Arow); 
	 
 
class DELPHICLASS TArrowWindow; 
class PASCALIMPLEMENTATION TArrowWindow : public Extctrls::TPanel  
{ 
	typedef Extctrls::TPanel inherited; 
	 
private: 
	TArrowDirection Dir; 
	Windows::TPoint Arrow[9]; 
	 
public: 
	__fastcall TArrowWindow(Classes::TComponent* AOwner, TArrowDirection direction); 
	virtual void __fastcall Loaded(void); 
	 
protected: 
	virtual void __fastcall CreateWnd(void); 
	virtual void __fastcall Paint(void); 
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params); 
public: 
	#pragma option push -w-inl 
	/* TCustomPanel.Create */ inline __fastcall virtual TArrowWindow(Classes::TComponent* AOwner) : Extctrls::TPanel( 
		AOwner) { } 
	#pragma option pop 
	 
public: 
	#pragma option push -w-inl 
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TArrowWindow(void) { } 
	#pragma option pop 
	 
public: 
	#pragma option push -w-inl 
	/* TWinControl.CreateParented */ inline __fastcall TArrowWindow(HWND ParentWindow) : Extctrls::TPanel( 
		ParentWindow) { } 
	#pragma option pop 
	 
}; 
 
 
class DELPHICLASS TPopupButton; 
class PASCALIMPLEMENTATION TPopupButton : public Controls::TCustomControl  
{ 
	typedef Controls::TCustomControl inherited; 
	 
private: 
	AnsiString FCaption; 
	bool FFlat; 
	 
protected: 
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params); 
	 
public: 
	virtual void __fastcall Paint(void); 
	virtual void __fastcall CreateWnd(void); 
	 
__published: 
	__property AnsiString Caption = {read=FCaption, write=FCaption}; 
	__property bool Flat = {read=FFlat, write=FFlat, nodefault}; 
public: 
	#pragma option push -w-inl 
	/* TCustomControl.Create */ inline __fastcall virtual TPopupButton(Classes::TComponent* AOwner) : Controls::TCustomControl( 
		AOwner) { } 
	#pragma option pop 
	#pragma option push -w-inl 
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TPopupButton(void) { } 
	#pragma option pop 
	 
public: 
	#pragma option push -w-inl 
	/* TWinControl.CreateParented */ inline __fastcall TPopupButton(HWND ParentWindow) : Controls::TCustomControl( 
		ParentWindow) { } 
	#pragma option pop 
	 
}; 
 
 
class DELPHICLASS TIntList; 
class PASCALIMPLEMENTATION TIntList : public Classes::TList  
{ 
	typedef Classes::TList inherited; 
	 
private: 
	TImageChangeEvent FOnChange; 
	int FCol; 
	int FRow; 
	void __fastcall SetInteger(int Index, int Value); 
	int __fastcall GetInteger(int Index); 
	AnsiString __fastcall GetStrValue(); 
	void __fastcall SetStrValue(const AnsiString Value); 
	 
public: 
	__fastcall TIntList(int Col, int Row); 
	__property int Items[int index] = {read=GetInteger, write=SetInteger/*, default*/}; 
	HIDESBASE void __fastcall Add(int Value); 
	HIDESBASE void __fastcall Delete(int Index); 
	__property AnsiString StrValue = {read=GetStrValue, write=SetStrValue}; 
	 
__published: 
	__property TImageChangeEvent OnChange = {read=FOnChange, write=FOnChange}; 
public: 
	#pragma option push -w-inl 
	/* TList.Destroy */ inline __fastcall virtual ~TIntList(void) { } 
	#pragma option pop 
	 
}; 
 
 
class DELPHICLASS TSortIndexList; 
class PASCALIMPLEMENTATION TSortIndexList : public TIntList  
{ 
	typedef TIntList inherited; 
	 
public: 
	void __fastcall AddIndex(int ColumnIndex, bool Ascending); 
	int __fastcall FindIndex(int ColumnIndex); 
	void __fastcall ToggleIndex(int ColumnIndex); 
public: 
	#pragma option push -w-inl 
	/* TIntList.Create */ inline __fastcall TSortIndexList(int Col, int Row) : TIntList(Col, Row) { } 
	#pragma option pop 
	 
public: 
	#pragma option push -w-inl 
	/* TList.Destroy */ inline __fastcall virtual ~TSortIndexList(void) { } 
	#pragma option pop 
	 
}; 
 
 
class DELPHICLASS TFilePicture; 
class PASCALIMPLEMENTATION TFilePicture : public Classes::TPersistent  
{ 
	typedef Classes::TPersistent inherited; 
	 
private: 
	AnsiString FFilename; 
	int FWidth; 
	int FHeight; 
	Graphics::TPicture* FPicture; 
	void __fastcall SetFileName(const AnsiString Value); 
	 
public: 
	void __fastcall DrawPicture(Graphics::TCanvas* Canvas, const Windows::TRect &r); 
	virtual void __fastcall Assign(Classes::TPersistent* Source); 
	 
__published: 
	__property AnsiString Filename = {read=FFilename, write=SetFileName}; 
	__property int Width = {read=FWidth, nodefault}; 
	__property int Height = {read=FHeight, nodefault}; 
public: 
	#pragma option push -w-inl 
	/* TPersistent.Destroy */ inline __fastcall virtual ~TFilePicture(void) { } 
	#pragma option pop 
	 
public: 
	#pragma option push -w-inl 
	/* TObject.Create */ inline __fastcall TFilePicture(void) : Classes::TPersistent() { } 
	#pragma option pop 
	 
}; 
 
 
//-- var, const, procedure --------------------------------------------------- 
 
}	/* namespace Advobj */ 
#if !defined(NO_IMPLICIT_NAMESPACE_USE) 
using namespace Advobj; 
#endif 
#pragma option pop	// -w- 
#pragma option pop	// -Vx 
 
#pragma delphiheader end. 
//-- end unit ---------------------------------------------------------------- 
#endif	// AdvObj 