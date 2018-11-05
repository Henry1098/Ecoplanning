//  ISAMD_H

#ifndef __ISAMD_H
#define __ISAMD_H

#ifdef __cplusplus
extern "C" {
#endif

class  realisam
{

 public:

  realisam(void);
 ~realisam(void);
 int  OpenEngine(char *FileName,short BlockSize,char *ndx, char*dat);
 int  CloseEngine(void);
 int  SetIndexMode(short Index, short Value);
 int  WriteRecord(char *pdata,int len);
 int  RewriteRecord(char *pdata,int len, int RecNumber);
 int  DeleteRecord(int RecNumber);
 int  ReadRecord(char *pdata,int RecNumber);
 int  GetNewRecordNumber();
 int  WriteKey(short Index,char *Key,int RecNumber);
 int  DeleteKey(short Index,char *Key,int RecNumber);
 int  ReadFirstKey(short Index,char *ReturnKey,int *RecNumber);
 int  ReadNextKey(char *ReturnKey ,int *RecNumber);
 int  ReadLastKey(short Index,char *ReturnKey,int *RecNumber);
 int  ReadPrevKey(char *ReturnKey ,int *RecNumber);
 int  ReadDirectKey(short Index,char *Key, char *ReturnKey, int *RecNumber);
 int  NumberOfKeys(short Index);
 int  RecordLength(int RecNumber);
 int  Version(char *p);
 int  GetIndexMode(int ndx);
 int  DeleteIsam(char *indexname,char *dataname);
 int  CloseReopen(char *FileName,short BlockSize,char *ndx, char *dat);

};

#ifdef __cplusplus
}
#endif

#endif