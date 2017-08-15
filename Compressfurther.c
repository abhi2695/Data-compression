#include"header.h"
#include"declaration.h"
int Compressfurther(int cl)
{	
	printf("%s: Begins\n",__func__);
	char *ekey1;
	int ndc,cfd,cl1;
	char*(*Mainarrayptr)(int);
	Mainarrayptr=Create_Master_Array;
	int (*clptr)(int);
	clptr=Code_length;
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;
	int (*Compressptr[])(int,char*)={Compression2,Compression3,Compression4,Compression5,Compression6,Compression7};
	
	printf("Enter the name of compressed file which you want to compress further\n");
	cfd=Openfileptr("O_RDONLY");
	lseek(cfd,0,SEEK_SET);
	ekey1=Mainarrayptr(cfd);
	ndc=strlen(ekey1);
	cl1=clptr(ndc);
	
	if(cl1==cl)
		printf("Cannot Compress further\n");	
	else
	{
		printf(" Compress further initiated\n");	
		 lseek(cfd,0,SEEK_SET);
		cl1-=2;
		Compressptr[cl1](cfd,ekey1);
	}
}
