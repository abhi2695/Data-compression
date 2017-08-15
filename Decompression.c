#include"header.h"
#include"declaration.h"
int Decompression()
{
	char *ekey;
	int cfd,efd,cl,ndc;
	
	int (*Openfileptr)(char*);
        Openfileptr=Open_File;
        int (*Decompressptr[])(int,char*)={Decompression2,Decompression3,Decompression4,Decompression5,Decompression6,Decompression7};
	char*(*Masterarrayptr)(int);
	Masterarrayptr=Create_Master_Array;
        int (*Clptr)(int);
        Clptr=Code_length;	
	
	printf("Enter Compressed file name\n");
	cfd=Openfileptr("O_RDONLY");
	printf("Enter Encryption key\n");
	efd=Openfileptr("O_RDONLY");

	ekey=Masterarrayptr(efd);
	ndc=strlen(ekey);
	cl=Clptr(ndc)-2;
	Decompressptr[cl](cfd,ekey);

	close(cfd);	
	close(efd);
}	
		
