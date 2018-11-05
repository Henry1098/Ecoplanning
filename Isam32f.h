
//  LGISAM.H

#ifndef __ISAM32_H
#define __ISAM32_H




#include <stdio.h>
#include <stdlib.h>
#include <dir.h>

#ifdef __cplusplus
extern "C" {
#endif



#define INDEX_LENGTH         1024    /* length of an index record    */
#define NUMBER_OF_INDEXES    64      /* maximum number of indexes    */
#define KEYMAX               100     /* buffer size for key + \0     */
#define HEIGHT               12      /* maximum height of tree       */
#define LMAX_PATH             MAXPATH     /* size of \path\filename.ext   */
#define RECORD_ADDR          4       /* bytes needed to store tiebrk */
#define MODE_READ            "r+b"
#define MODE_WRITE           "w+b"


// ROOT DESCIPTION   // size 1024
//  ADDR   LEN   VAR
//  0      4     nai    Next available index
//  4      4     fli    First linked index record

//  8      10     root (4) + multiKey (2) + Nbkey (4) for index 0
//  18     10     index 1




// INDEX32 DESCRIPTION  // size 1024
//  ADDR   LEN   VAR
//  0      2     nkey   Number of key in this index
//  2      2     position Key1
//  4      2     position Key2
//  6      2     position Keyn
//  ......
//  x1     2     ptrbeg  = pointer where linkage (left,above,roght) start
//  x2     4     ao      = ptr
//  x3     kl1   Key1 + 4 byte for data1 record pointer
//  x4     kl2   Key2 + 4 bytes pointer
//  xnn    kln   Keyn + 4 bytes pointer

//  x10    4     left pointer
//  x10+4  4     above pointer
//  x10+8  4     right pointer
//  filler


class isam
{
    public:
    isam();
    ~isam();

     short  Lire( short Index,char *Key,int *DataRec,char  *RKey);
     short  Ecrire( short Index,char *Key,int RecNumber);   //,int *DataRec);
     short  Suivante(char *RKey, int *DataRec);
     short  Precedente(char *RKey, int *DataRec);
     short  Effacer( short Index,char *Key,int delrec);
     short  Premiere( short Index,char *RKey,int *DataRec);
     short  Derniere( short Index,char *RKey, int *DataRec);
     short  Ouvrir(char *FileName);
     short  Fermer(void);
     short  Multi( short Index, short value);
     int     Cles( short Index);

    private:


    FILE *fileptr;                                  // fp
    char radical[LMAX_PATH];                // Idxname
    short Erreur, Compte;                     // er,count
    char Temp_Cle[KEYMAX + 1];             // saveikey

    char Tmp_01[INDEX_LENGTH],            // abuf
	 Tmp_03[INDEX_LENGTH],            // abuft
	 Tmp_02[INDEX_LENGTH],            // abufl  
	 Tmp_04[INDEX_LENGTH];           // abufr
    int I_Ref, I_Pl, I_Suiv, I_Gauche, I_Droite, Racine[NUMBER_OF_INDEXES]; // nai, fli,nir,lir,rir, root[NUMBER_OF_INDEXES];
    int Nb_Cles[NUMBER_OF_INDEXES]; // nbkey[NUMBER_OF_INDEXES];
    short  TLong_Cle,Long_Cle;             //ikeylen, keylen;
    int P_AHOO,P_Gauche,P_Haut,P_Droit,E_Gauche,E_Droit,E_Gen,Ptr_ES, IEnreg;   //   ao, lpt, upt, rpt, dl, dr, dx, iorec, drec;
     short  ICle, Debut, Indice, P_X, Resultat;          //nkey, ptrbeg, ikn,ht,loc
    char Cle[KEYMAX+1], SSCle[KEYMAX+1], SCle_Gauche[KEYMAX+1]; //key, skey, leftkey[KEYMAX+1];
     short  Bloc_Index[NUMBER_OF_INDEXES];   //ainattr[NUMBER_OF_INDEXES];
    int Ind_EnrN[HEIGHT], Ind_EnrL[HEIGHT];  // int irecn[HEIGHT], irecl[HEIGHT];

      int  var32;

    short  fctler1(char index, char *skey); 
    short  inter(char index, char ops, char *ikey, int irec);
    void rech(char *ikey,  short index);
    void en_avant(void);
    void en_arriere(void);
    void leprem( short index);
    void leder( short index);
    short fctler2(char index, char *skey);
    void place(void);
    void libere(int recno);
    short fctler3(char index, char *skey);
    void pissenlit( short index);
    void separe(char *buffer);
    void insere(char *ikey, int dp, char *buffer);
    void change(void);
    void effacex(char *buffer);
    void trouve(char *buffer);
    void rechcle(char *buffer, char *skey);
    void decache(char *buffer);
    void cache(char *buffer);
    short  fctler4(char index, char *skey);
    void lirex(int iorec, char *buffer);
    void ecrirex(int iorec, char *buffer);
    void dupliquer(char *buffer, char *string,  short start,  short len);
    void remplir(char *buffer, char fill,  short len);
    short  comparer(char *string1, char *string2,  short len);
    void linkc(char *buffer, int number);
    short  fctler5(char index, char *skey);


};


// DATA FILE ORGANIZATION

// first record
//    firstfree pointer (int )
//    data bloc size    (long) ==> physical bloc size = databloc size + 8


// Other records
//    next bloc pointer (long)  or 0L if last
//    flag delete       (int)
//    data length       (int)  must be <= databloc size



// To delete a data record, use the Rewrite with a 0 length parameter



class vardata
{

  public :

  int firstfree;
  FILE *fdata;
  char *bufio;   //[BLOCSIZE+1];
  char *buftmp;
  short DATASIZE;
  short BLOCSIZE;
  short var16;
  int var32;

  public:
  vardata(void);
  ~vardata(void);
  short OpenData(char *FileName, short BlocSize);
  short CloseData(void);
  short ReadFirstDataBlock(char *pdata,int record);
  int ReadData(char *pdata,int record);
  int RecordLength(int record);
  int WriteData(char *pdata,int len);
  short RewriteData(char *pdata,int len, int record);
  short DeleteData(int record);
  int GetAvailRecord();
  void dupliquer(char *buffer, char *string,  short start,  short len);
  void remplir(char *buffer, char fill,  short len);
  short  comparer(char *string1, char *string2,  short len);
  void readbuf(int iorec, char *buffer);
  void writebuf(int iorec, char *buffer);


};


class _export genbase
{

 public:

  genbase(void);
 ~genbase(void);
 int  OpenEngine(char *FileName,short BlockSize);
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
 int  Version(void);

 private:

 isam     *doctitl;
 vardata  *doc;

};

#ifdef __cplusplus
}
#endif

#endif