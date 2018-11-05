//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <stdio.h>
#include "modTSLIsam.h"

#pragma hdrstop
//---------------------------------------------------------------------------


typedef struct  tch
  {
   AnsiString  LockKey;
   AnsiString  Data;
  } T_tch;






// **********************************************
// TSLIsam::TSLIsam
// **********************************************
// PARAMETERS  :   NONE

TSLIsam::TSLIsam(bool dup)
{
 int i;  AnsiString K;
 char key[10];

 TSL = new TStringList;
 CurrentPointer = -1;
 TSL->Sorted = true;

 if (dup) TSL->Duplicates = dupAccept;
 else TSL->Duplicates = dupIgnore;
 strcpy(DBLockKey,"");

 for (i=0;i<256;i++)
  {

   Index[i] = "";
  }

}

// **********************************************
// TSLIsam::~TSLIsam
// **********************************************
// PARAMETERS  :   NONE

TSLIsam::~TSLIsam(void)
{
 // delete TSL and All associated OBjects
 int i;
 for (i = 0; i < TSL->Count; i++) delete (T_tch *)TSL->Objects[i];
 TSL->Free();

}


// **********************************************
//   WRITERECORD
// **********************************************
// rc=1; ok
// rc=2; locked
// rc = 3 ... too long
int  TSLIsam::WriteRecord(char *pdata,char *Key,char *lockkey)
{
 T_tch *IRec;  int rc;
  AnsiString S;
 int indx;

 S=AnsiString(Key);

 if (Locked(S,lockkey)) return 2;

 if (strlen(pdata) > MAX_DATA) return 3;
 indx = TSL->IndexOf(S);
 if (indx < 0)  // doesnt exist;
  {
   IRec = new T_tch();
   IRec->LockKey   = "";
   IRec->Data = AnsiString(pdata);
   TSL->AddObject(AnsiString(S),(TObject *) IRec);
  }
 else
  {
   IRec= new T_tch;
   IRec =(T_tch *)TSL->Objects[indx];
   IRec->LockKey  = AnsiString(lockkey);
   IRec->Data = AnsiString(pdata);
   }
 return 1;
}



// *********************************************************
//
//   TSLIsam::DELETERECORD
//
// *********************************************************

// rc = 1 ok;
//rc=0; not found
//rc = 2 locked
int  TSLIsam::DeleteRecord(char *Key,char *lockkey)
{
 AnsiString S;
 T_tch *IRec;  int indx;
 S = AnsiString(Key);
 if (Locked(S,lockkey)) return 2;

 indx = TSL->IndexOf(S);
 if (indx < 0) return 0;
 else
  {

   delete (T_tch *)TSL->Objects[indx];
   // remove the index entry
   TSL->Delete(indx);
   Update_Index(Key,'D');
   return 1;
   }

}



// *********************************************************
//
//   TSLIsam::READRECORD
//
// *********************************************************

// rc = 1 ok;
//rc=0; not found  return value of next key in retKey
//rc = 2 locked


int  TSLIsam::ReadRecord(char *pdata,char *Key,char *RetKey,char *lockkey)
{
 int indx;   T_tch *IRec;
 AnsiString S,SKey,RKey;  char c; int ic;

 SKey = AnsiString(Key);

 indx = TSL->IndexOf(SKey);
 if (indx >= 0)
   {
     IRec = new T_tch;
     IRec =(T_tch *)TSL->Objects[indx];
     strcpy(pdata,IRec->Data.c_str());
     strcpy(RetKey,Key);
     S = AnsiString(RetKey);
     if (Locked(S,lockkey)) return 2;

     CurrentPointer = indx;
     return 1;
   }
 else
   { // return RetKey just >  Key
    c = Key[0]; ic = (int) c;
    RKey = GoUP(SKey,ic);
    if (RKey != "")
      {
       indx = TSL->IndexOf(RKey);
       if (indx >= 0)
        {
         IRec = new T_tch;
         IRec =(T_tch *)TSL->Objects[indx];
         strcpy(pdata,IRec->Data.c_str());
         strcpy(RetKey,RKey.c_str());
         CurrentPointer = indx;
        }

       return 0;
      }
     else
      { strcpy(pdata,"");
      strcpy(RetKey,"");
       return 0;
      }
   }
}


// **********************************************
//   GETNEXTKEY
// **********************************************
// rc = 0 --> No next key;
// rc = 1 Next Key in Retkey
int  TSLIsam::GetNextKey(char *RetKey)
{
 char Result[200];
 CurrentPointer++;
 if (CurrentPointer >= TSL->Count)
   { CurrentPointer--;
     strcpy(RetKey,"");
     return 0;
   }
 strcpy(RetKey,TSL->Strings[CurrentPointer].c_str());
 return 1;

}

// **********************************************
// TSLIsam::RECORDLENGTH
// **********************************************

// rc = 1 ok;
//rc=0; not found
//rc = 2 locked
int TSLIsam::RecordLength(char *Key,char *lockkey)
{

 int indx;  T_tch *IRec; AnsiString S;
 S = AnsiString(Key);
 S=AnsiString(Key);
 if (Locked(S,lockkey)) return 2;

 indx = TSL->IndexOf(AnsiString(Key));
 if (indx <0) return 0;
 else
  {
   IRec = new T_tch;
   IRec =(T_tch *)TSL->Objects[indx];
   //strcpy(RetKey,TSL->Strings[0].c_str());
   strcpy(databuf,IRec->Data.c_str());
   return (strlen(databuf));
  }
}


// *********************************************************
//
//   TSLIsam::READFIRSTKEY
//
// *********************************************************

// rc = 1 ok;
//rc=0; not found
//rc = 2 locked


int TSLIsam::ReadFirstKey(char *pdata, char *RetKey,char *lockkey)
{
int cnt;  T_tch *IRec; AnsiString S;

 strcpy(RetKey,"");  strcpy(pdata,"");
 cnt = TSL->Count;
 if (cnt==0) return 0;
 IRec = new T_tch;
 IRec =(T_tch *)TSL->Objects[0];
 strcpy(RetKey,TSL->Strings[0].c_str());

 S = AnsiString(RetKey);
 if (Locked(S,lockkey)) return 2;

 strcpy(pdata,IRec->Data.c_str());
 CurrentPointer = 0;
 return 1;
}


// **********************************************
//  READNEXTKEY
// **********************************************
// rc = 0 above last key;
// rc = 1 Next key found, value in RetKey, data in pdata
// rc = 2; locked
int TSLIsam::ReadNextKey(char *pdata, char *RetKey,char *lockkey)
{
 int newpointer,cnt;  T_tch *IRec;   AnsiString S;

 cnt = TSL->Count; if (cnt==0) return 0;
 newpointer = CurrentPointer; newpointer ++;
 if (newpointer >= TSL->Count) return 0;
 CurrentPointer++;
 IRec = new T_tch;
 IRec =(T_tch *)TSL->Objects[CurrentPointer];
 strcpy(RetKey,TSL->Strings[CurrentPointer].c_str());
  S = AnsiString(RetKey);
 if (Locked(S,lockkey)) return 2;
  strcpy(pdata,IRec->Data.c_str());
 
 return 1;
}



 // **********************************************
//  READLASTKEY
// **********************************************
// rc = 0; no key ... db empty
// rc=1; Last Key in RetKey, data in pdata
// rc = 2 Locked
int TSLIsam::ReadLastKey(char *pdata, char *RetKey,char *lockkey)
{
 int cnt;  T_tch *IRec; AnsiString S;

 cnt = TSL->Count; if (cnt==0) return 0;
 CurrentPointer = cnt-1;
 IRec = new T_tch;
 IRec =(T_tch *)TSL->Objects[CurrentPointer];
 strcpy(RetKey,TSL->Strings[CurrentPointer].c_str());

 S = AnsiString(RetKey);
 if (Locked(S,lockkey)) return 2;

 strcpy(pdata,IRec->Data.c_str());
 return 1;
 }

// **********************************************
//    READPREVKEY
// **********************************************
// rc = 0; no key ... db empty
// rc=1; Prev Key in RetKey, data in pdata
// rc = 2 Locked

int TSLIsam::ReadPrevKey(char *pdata, char *RetKey,char *lockkey)
{
int newpointer,cnt;  T_tch *IRec;  AnsiString S;

 cnt = TSL->Count; if (cnt==0) return 0;
 newpointer = CurrentPointer; newpointer --;
 if (newpointer < 0 ) return 0;
 CurrentPointer--;
 IRec = new T_tch;
 IRec =(T_tch *)TSL->Objects[CurrentPointer];
 strcpy(RetKey,TSL->Strings[CurrentPointer].c_str());

 S = AnsiString(RetKey);
 if (Locked(S,lockkey)) return 2;

 strcpy(pdata,IRec->Data.c_str());
 return 1;
}




// **********************************************
//
// TSLIsam::OPENENGINE
//
// **********************************************

// file not found , created
// file found
// rc=-1;  // cannot open File (Directory error)
// rc=3  memory overflow
// rc=-4  record structure not correct  (field "<key> Empty)
// RC = record count

int TSLIsam::OpenEngine(char *FileName,char *lockkey)
{
 int rc;   FILE *fp; int cnt;
 T_tch * IRec;  char Key[500];
 char c,lastc;  AnsiString SK;
 int indx;

 fp=fopen(FileName,"rb");
 if (fp==NULL)
     {
      fp=fopen(FileName,"wb");
      if (fp==NULL) return -1;
      fclose(fp);
      fp = fopen(FileName,"rb");
     }

 lastc = 0;
 while (!feof(fp))
   {
     strcpy(recordbuf,"");
     fgets(recordbuf,MAX_DATA,fp);    // MAX_DATA


     if (strlen(recordbuf)> 11)  // <key>x</key>
       {
        ExtractValue(databuf,recordbuf,"K",0);

        if (strlen(databuf) > 200) { fclose(fp); return -4;}
        if (strlen(databuf) == 0) { fclose(fp); return -4;}
        strcpy(Key,databuf);

        Update_Index(Key,'I');


        ExtractValue(databuf,recordbuf,"D",0);
        Insert_CRLF(databuf);
        IRec =        new T_tch;
        IRec->LockKey   = "";
        IRec->Data = AnsiString(databuf);
        TSL->AddObject(AnsiString(Key),(TObject *) IRec);
       }
   }
 cnt = TSL->Count;

 fclose(fp);
 SK=Index['a'];
 return cnt;
}


// **********************************************
//    CLOSE ENGINE
// **********************************************
// rc = -1;  file open error
// rc = Count;  OK
//

int TSLIsam::CloseEngine(char *FileName,char *lockkey)
{
 FILE *fp;  int i,l,count;
 T_tch * IRec;  char Key[500];
 int xcount; char *p;  char Clef[200];

 fp=fopen(FileName,"wb");
 if (fp==NULL) return -1;
 count = TSL->Count;
 xcount=0;
 for (i=0;i < count;i++)
     {
      IRec = new T_tch;
      IRec = (T_tch*) TSL->Objects[i];
      strcpy(Clef,TSL->Strings[i].c_str());
      strcpy(recordbuf,"<K>");
      strcat(recordbuf,TSL->Strings[i].c_str());
      strcat(recordbuf,"</K>");
      strcpy(databuf,IRec->Data.c_str());
      Remove_CRLF(databuf);
      strcat(recordbuf,"<D>");
      strcat(recordbuf,databuf);
      strcat(recordbuf,"</D>\n");
      l=strlen(recordbuf);
      fwrite(recordbuf,1,l,fp);
      xcount++;
     }
  fclose(fp);
  return xcount;
}


// **********************************************
//
// TSLIsam::NUMBEROFKEY
//
// **********************************************
// rc = Number of keys
int TSLIsam::NumberOfKeys()
{
 return TSL->Count;
}



// **********************************************
//
// TSLIsam::VERSION
//
// **********************************************
int TSLIsam::Version(char *p)
{
 strcpy(p,"Version 1.0");
 return 1;
}



// **********************************************
//    LOCKRECORD
// **********************************************
// rc = 0  // Record was already locked with another Key
// rc = 1  // Record Locked
// rc = 2  // No record for the key

int TSLIsam::LockRecord(char *RecKey, char *lockkey)
{
 T_tch *IRec; int indx;  AnsiString K,KK;

 indx = TSL->IndexOf(AnsiString(RecKey));
 if (indx < 0) return 2;
  KK = AnsiString(lockkey);
 IRec= new T_tch;
 IRec =(T_tch *)TSL->Objects[indx];
 K = IRec->LockKey;
 //IRec->Data = AnsiString(pdata);
 if (K=="") { IRec->LockKey = KK; return 1; }
 else
  {
   if (KK == K) return 1;  // same key
   else return 0;
  }

}

// **********************************************
//  UNLOCKRECORD
// **********************************************
// rc = 0  Record is still locked with another Key
// rc = 1  Record unlocked
// rc = 2  No Record existing

int TSLIsam::UnlockRecord(char *RecKey, char *lockkey)
{
  T_tch *IRec; int indx;  AnsiString K,KK;
  indx = TSL->IndexOf(AnsiString(RecKey));
  if (indx < 0) return 2;
  KK = AnsiString(lockkey);
  IRec= new T_tch;
  IRec =(T_tch *)TSL->Objects[indx];
  K = IRec->LockKey;
 //IRec->Data = AnsiString(pdata);
  if (K=="") { return 1; }   // record was already unlocked
 else
  {
   if (KK == K) { IRec->LockKey=""; return 1; }
      else return 0;
  }

}


// **********************************************
//   LOCKDB
// **********************************************
// rc = 0;
// rc = 1; OK ... locked
// rc = 2;  Already locked , with the same Key

int TSLIsam::LockDB(char *lockkey)
{
 if (strlen(DBLockKey))
   {
    if (strcmp(DBLockKey,lockkey)==0) return 2;
    else return 0;
   }

 else
   {
    strcpy(DBLockKey,lockkey);
    return 1;
   }



}

// **********************************************
//    UNLOCKDB
// **********************************************
// rc = 0  Wrong Key
// rc = 1  OK -> unlocked
// rc = 2  was already unlocked

int TSLIsam::UnlockDB(char *lockkey)
{
  if (strlen(DBLockKey))
    {
     if (strcmp(DBLockKey,lockkey) == 0)
       {
        strcpy(DBLockKey,""); return 1;
       }
     else return 0;

    }
  else
    {
     return 2;
    }

}


// **********************************************
//   GOUP
// **********************************************
AnsiString __fastcall TSLIsam::GoUP(AnsiString SK,int ic)
{
  int i,ix;  AnsiString Temp,Result;  char tmp[200];
  char cref,c;
   Result = "";

  if (TSL->Count == 0) return "";

  if (Index[ic]==NULL)
    {
      Result = "";
     for (i = ic+1; i < 256 ; i++)
       {
        Result = Index[i];
        if (Result != "")
            break;
       }
     return Result;
    }
  else
    {
     // lire les strings
     ix = TSL->IndexOf(Index[ic]);
     if (ix < 0) ix=0; // return Result;
     Temp = TSL->Strings[ix];
     while (ix < TSL->Count)
       {
        Temp = TSL->Strings[ix];
        if (Temp > SK)  //
          {
           Result = Temp;
           break;
          }

        ix++;
       }
     return Result;
    }

}

// **********************************************
//    UPDATE_INDEX
// **********************************************
void __fastcall TSLIsam::Update_Index(char *Key,char OP)
{
 int indx; AnsiString SK;

 indx  = (int) Key[0]; SK = AnsiString(Key);
 if (OP == 'I')
   {
     if (Index[indx]=="") Index[indx] = SK;
      else
       {
        if (SK <= Index[indx])
        Index[indx] = SK;
       }
   }
 if (OP == 'D')     // $$$$$$$$$$$$$$$$
   {
    


   }

}

// **********************************************
//    EXTRACT_VALUE
// **********************************************
int __fastcall TSLIsam::ExtractValue(char *result, char *buff, char *tag, int posdeb)
{ char tmp[250];char *p,*p1,*p2; int pos,l;

 result[0]=0; strcpy(tmp,"<"); strcat(tmp,tag); strcat(tmp,">"); p = strstr(buff,tmp);
 l=0;
 if (p)
   {strcpy(tmp,"</"); strcat(tmp,tag); strcat(tmp,">");p1= strstr(buff,tmp);
    if (p1) {p2=p + strlen(tag)+2; l= p1-p2; strncpy(result,p2,l); result[l]=0; }
   }
 return l;
}

// **********************************************
//   REMOVE CRLF
// **********************************************
void __fastcall TSLIsam::Remove_CRLF(char *text)
{
 char *p;

 p=strstr(text,"\r"); while (p) { *p = '~'; p=strstr(text,"\r"); }
 p=strstr(text,"\n"); while (p) { *p = '¤'; p=strstr(text,"\n"); }

}

// **********************************************
//  INSERT_CRLF
// **********************************************
void __fastcall TSLIsam::Insert_CRLF(char *text)
{
 char *p;
 p=strstr(text,"~"); while (p) { *p = '\r'; p=strstr(text,"~"); }
 p=strstr(text,"¤"); while (p) { *p = '\n'; p=strstr(text,"¤"); }
}

// **********************************************
//  LOCKED
// **********************************************

// locked if DB locked and lk not = Lock Key
// Check if record locked with the same key

bool __fastcall TSLIsam::Locked(AnsiString S,char *lk)
{
 T_tch *IRec; int indx;  AnsiString K,KK;

 if (strlen(DBLockKey))
   {
    if (strcmp(DBLockKey,lk) != 0) return true;
   }

 indx = TSL->IndexOf(S);
 if (indx < 0) return false;
 KK = AnsiString(lk);
 IRec= new T_tch;
 IRec =(T_tch *)TSL->Objects[indx];
 K = IRec->LockKey;
 if (K=="") { return false; }   // not locked
 else
  {
   if (KK == K) return false;  // same key
   else return true;
  }

}

int  TSLIsam::GetIndexValue(int i, char *ind)
{
 strcpy(ind,Index[i].c_str());
 return 1;
}



//---------------------------------------------------------------------------
