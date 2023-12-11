#define ASSIGNMENT "HW #14.1: Ken Pottebaum \n"
// This version terminates input when an input string is too long.
//#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TSIZE 101 // Size of title string
#define ASIZE 51  // Size of author string
#define YSIZE 7   // Size of year string--include space for '\n' (possibly 2 chars) and '\0'.
#define FSIZE 51  // Size for the filename.
#define FILENAMESIZE 30
//Remember to end the path name with "\\"
#define PATHNAME ""
#define TEXTINPUT "HW14Data.txt" // Text input filename.
#define BINARYFILE "HW14Binary" // Binary filename.
#define BINARYEXT ".xxx"
#define FLUSH while (getchar()!='\n')

struct stbook {
	char title[TSIZE], author[ASIZE], year[YSIZE];
};
typedef struct stbook ITEM;  // ITEM is a type structure containing book info.
typedef struct stNode {
	ITEM Item;
	struct stNode *pNext;
} NODE;                	// NODE is a structure containg item and the pointer next.
typedef NODE *PNODE;  // PNODE type is a pointer to a Node.

PNODE   AppendAfter(const PNODE *pCur, const ITEM *pItem);  // Appends 1 node.
PNODE   AppendFromTextFile(PNODE *pHead);   // Appends multiple nodes from text file.
   // If pHead==NULL, it is set to pointer to the first node added.
   // The return value is the pointer to the last node added.
void		ClearLine(void);  // Clears input buffer through '\n'.
unsigned	CountRecords(const PNODE *pHead);  // Counts the number of nodes.
PNODE		GetRecordNum(const PNODE *pHead, unsigned n, ITEM * pItem);
int 		HasAnEnter(char * pstr);			// Checks string for a \n.
void		InitializeList(PNODE *pHead);    // Clears & initializes list.
PNODE		ListEnd(const PNODE *pCur);   	// Returns ptr to last node in a list. 
int		Menu(void);  							// Prompts for and returns selection.
void 		ListAllRecords(const PNODE *pHead);  // Prints all the records in the list.
void 		PrintRecord(const PNODE *pHead);  // Prompts for record #, and prints record.
void 		WriteBinaryFile(const PNODE *pHead,
				char Filename[], int Fsize);  // Writes data to a binary file
FILE* 	OpenWrBinaryFile(char *pFilename, int nLen);
char* 	BuildFilePath(char *pFull,char *pName,char *pPath,char *pExt);
void 		GetFilename(char* pFilename, int nLen, const char* pPrompt);

int main(void){	
	PNODE pList = NULL;  // plist is a pointer to the head of the list.
	char WrFilename[FSIZE] = BINARYFILE;
	int ch = 0;
	fputs(ASSIGNMENT,stdout);
	while ((ch=Menu())!='q') {
		switch (ch) {
			case 'i': InitializeList(&pList);  // Initialize list, clearing any existing list.
						break;
			case 'a': AppendFromTextFile(&pList);  // Sets pList if it was NULL,
						break;
			case 'p': PrintRecord(&pList);  // Prompts for record #, and prints record.
						break;
			case 'l': ListAllRecords(&pList);  // Prints all the records in the list.
						break;
			case 'w': WriteBinaryFile(&pList,WrFilename,FSIZE);	// Writes data to a binary file.	 
		}
	}
	InitializeList(&pList);  // Initializes list, freeing any allocated memory.
	return 0;
}

PNODE AppendAfter(const PNODE *pCur, const ITEM *pItem) {
	PNODE pNew;
	pNew = malloc(sizeof(NODE));
	if (pNew) {
		pNew->Item = *pItem;
		if (*pCur) {
			pNew->pNext = (*pCur)->pNext;
			(*pCur)->pNext = pNew;
		} else {
			pNew->pNext = NULL;
		}
	}
#ifdef DEBUG
	printf("AppendAfter pNew=%p\n",pNew);
#endif
	return pNew;	
}

PNODE AppendFromTextFile(PNODE *pHead) {
	ITEM item;
	unsigned int Count=0;
	PNODE pCur = ListEnd(pHead); // Find last node in current list
	FILE * fp = fopen(TEXTINPUT,"r");
	if (fp) {
		while ((fgets(item.title,TSIZE,fp)) && (fgets(item.author,ASIZE,fp)) && (fgets(item.year,YSIZE,fp)) ) {
#ifdef DEBUG
			printf("%s  %s  %s",item.title,item.author,item.year);
#endif
			if ( HasAnEnter(item.title) && HasAnEnter(item.author) && HasAnEnter(item.year) ){
				pCur = AppendAfter(&pCur,&item);
				if (pCur) {
					Count++;
					if (*pHead==NULL) *pHead = pCur;
				} else {
					printf("** Memory allocation failed **\n");
					break;
				}
			} else {
				printf("** File input line was too long, aborting operation **\n" 
						"   Book info read is:\n");
				printf("%s%s%s\n",item.title,item.author,item.year);	
				break;
			}
		}
		fclose(fp);
		printf("Appended %u records from %s.\n",Count,TEXTINPUT);
	} else printf("** Failed to open %s. **\n",TEXTINPUT);
	return pCur;
}

void ClearLine(void) {
	while (getchar()!='\n') ;
}

unsigned CountRecords(const PNODE *pHead) {
	unsigned i;
	PNODE ptmp=*pHead;
	if (ptmp)
		for (i=1; (ptmp->pNext); i++)
			ptmp = ptmp->pNext;
	else i = 0;
#ifdef DEBUG
	printf("CountRecords = %u\n",i);
#endif
	return i;
}

PNODE GetRecordNum(const PNODE *pHead, unsigned n, ITEM *pItem) {
	PNODE pCur = *pHead;
	unsigned i;
	for (i=1; (i<n) && (pCur); i++)
		pCur = pCur->pNext;
	if (pCur)
		*pItem = pCur->Item;
	return pCur;
}	

//This function could be replaced with:
//strchar('/n',pstr);

int HasAnEnter(char * pstr) {
	while ((*pstr!='\0') && (*pstr!='\n')) 
		pstr++;
	return *pstr=='\n';
}
	
void InitializeList(PNODE *pHead) {
	PNODE ptmp;
#ifdef DEBUG
	printf("Initialize: %p  ",*pHead);
#endif
	while (*pHead) {
		ptmp = (*pHead)->pNext; //Need the () so that the * applies to pHead and not to pNext.
		free(*pHead);
		*pHead = ptmp;
	}
#ifdef DEBUG
	printf(" %p\n",*pHead);
#endif
	fputs("Initialization completed\n",stdout);
}

// Prints all the records in the list.
void ListAllRecords(const PNODE *pHead){
	unsigned nRec;
	PNODE pCur;
	if ((pCur = *pHead)) {  // This is an assignment.
		for (nRec=0; (pCur); ){
			printf("\nContents of record #%u are: \n  %s  %s  %s",++nRec,
				pCur->Item.title, pCur->Item.author, pCur->Item.year);
			pCur = pCur->pNext;
		}
	} else printf("\nNo records available to print.\n");	
}

PNODE ListEnd(const PNODE *pCur) { // Finds end of the list.
	PNODE ptmp=*pCur;
	if (ptmp)
		while (ptmp->pNext)
			ptmp = ptmp->pNext;
	return ptmp;
}

int Menu(void) {
	char * pPrompt = "\nSelect operation from following list:\n" 
						" i) Initialize   a) Append         L) List\n"
						" p) Print        w) Write b File   q) quit\n"
						" Enter selection:  ";
	char * pChars = "ailpqw";
	int ch=0;
	fputs(pPrompt,stdout);
	while (strchr(pChars,ch=tolower(getchar()))==NULL)	{
		ClearLine();
		fputs(pPrompt,stdout);
	}
	ClearLine();
	return ch;
}

// Prompts for record # to be printed and prints record.
void PrintRecord(const PNODE *pHead) {
	unsigned nRec, nMax;
	ITEM PrintItem;
	PNODE pCur=NULL;
	nMax = CountRecords(pHead);
	if (nMax>0) {
		printf("Enter record # to print (1-%u):  ",nMax);
		if ( (scanf("%u",&nRec)) && (nRec>0 && nRec<=nMax))
			pCur = GetRecordNum(pHead,nRec,&PrintItem);
		else
			fputs("** Invalid input--aborting operation **\n",stdout);
		if (pCur)
			printf("\nContents of record #%u are: \n  %s  %s  %s",nRec,
				pCur->Item.title, pCur->Item.author, pCur->Item.year);
		ClearLine();
	} else fputs("\nNo records available to print.\n",stdout);
}

void WriteBinaryFile(const PNODE *pHead, char Filename[], int Fsize) { 
	unsigned int Count=0;
	PNODE pCur=*pHead;
	FILE *fp;
	if ((fp=OpenWrBinaryFile(Filename,Fsize))) {
		while ((pCur) && (fwrite(&pCur->Item,sizeof(ITEM),1,fp)==1)) { // Write out title, author, & year.
			Count++;
			pCur = pCur->pNext;
		}
		fclose(fp);
		printf("Wrote %u records to %s.\n",Count,Filename);
	} else printf("** Failed to open %s. **\n",Filename);
}

char * BuildFilePath(char *pFull, char *pName, 
				char *pPath, char *pExt) {
	//The calling function made sure that the pFull memory allocation is large enough.
	strcpy(pFull,pPath);
	strcat(pFull,pName);
	strcat(pFull,pExt);
	return pFull;
}

// Prompts for and reads in a filename.
void GetFilename(char* pFilename, int nLen, const char* pPrompt) {
	char NewName[nLen], *pc;
	printf(pPrompt,nLen);
	fgets(NewName,nLen,stdin);
	// Remove newline character or clear the buffer as necessary.
	for (pc=NewName; (*pc!='\0') && (*pc!='\n'); pc++); 
	if (*pc=='\n') *pc='\0';
	else
		FLUSH;
	if (NewName[0]!='\0')
		strcpy(pFilename,NewName);
}

// Returns file pointer for writing file or NULL.
FILE* OpenWrBinaryFile(char *pFilename, int nLen) {
	FILE *fp;
	char Fullname[sizeof(PATHNAME)+nLen+5]; // Large enough hold the full path and name.
	char *pChars="acoq";  // pChars points to a string containing valid menu selections.
	char ch='c', sMode[2][3]={"wb","ab"};	// sMode contains to 2 options for opening the file.
	char *pPrompt1 = "Enter a new filename without an extension (<%d characters)\n"
							"or press [Enter] to use the default name:\n";
	char *pPrompt2 = "File %s exists.  Do you want to:\n Append to the file,\n"
			" Overwrite the file,\n Change the filename,\n or Quit?\n"
			" Enter an 'a', 'c', 'o', or 'q': ";
	char *pPrompt3 = "Enter a new filename without an extension (<%d characters):\n";
			
	// Ask for user for filename.
	printf("The default file name is: %s\n",pFilename);
	GetFilename(pFilename,nLen,pPrompt1);
	
	// Loop until have file not found or user chose to overwrite, append, or quit.
	while ((ch=='c') && 
				(BuildFilePath(Fullname,pFilename,PATHNAME,BINARYEXT)) &&
				(fp = fopen(Fullname,"r"))) { 
		if (fp) 
			fclose(fp);
		printf(pPrompt2,pFilename);
		while (strchr(pChars,ch=tolower(getchar()))==NULL)	{
			FLUSH;
			printf(pPrompt2,pFilename);
		}
		FLUSH;
		if (ch=='c') 
			GetFilename(pFilename,nLen,pPrompt3);
	}
	// Do not open file if user chose 'q' to quit.
	return (ch!='q') ? fopen(Fullname,sMode[ch=='a']): NULL; // changes file mode to "ab" if append was selected.
}

//	HW #14.1: Ken Pottebaum
//	
//	Select operation from following list:
//	 i) Initialize   a) Append         L) List
//	 p) Print        w) Write b File   q) quit
//	 Enter selection:  i
//	Initialization completed
//	
//	Select operation from following list:
//	 i) Initialize   a) Append         L) List
//	 p) Print        w) Write b File   q) quit
//	 Enter selection:  a
//	Appended 15 records from HW14Data.txt.
//	
//	Select operation from following list:
//	 i) Initialize   a) Append         L) List
//	 p) Print        w) Write b File   q) quit
//	 Enter selection:  p
//	Enter record # to print (1-15):  1
//	
//	Contents of record #1 are:
//	  On Basilisk Station
//	  Weber, David
//	  1993
//	
//	Select operation from following list:
//	 i) Initialize   a) Append         L) List
//	 p) Print        w) Write b File   q) quit
//	 Enter selection:  w
//	The default file name is: HW14Binary
//	Enter a new filename without an extension (<51 characters)
//	or press [Enter] to use the default name:
//	
//	File HW14Binary exists.  Do you want to:
//	 Append to the file,
//	 Overwrite the file,
//	 Change the filename,
//	 or Quit?
//	 Enter an 'a', 'c', 'o', or 'q': c
//	Enter a new filename without an extension (<51 characters):
//	newfile
//	Wrote 15 records to newfile.
//	
//	Select operation from following list:
//	 i) Initialize   a) Append         L) List
//	 p) Print        w) Write b File   q) quit
//	 Enter selection:  q
//	Initialization completed
//	
//	--------------------------------
//	Process exited after 41.76 seconds with return value 0
//	Press any key to continue . . .
