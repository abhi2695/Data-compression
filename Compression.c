#include"header.h"
#include"declaration.h"
	
int Compression()
	{
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;
	int (*Compressptr[])(int,char*)={Compression2,Compression3,Compression4,Compression5,Compression6,Compression7};
	char*(*Masterarrayptr)(int);
        Masterarrayptr=Create_Master_Array;
        int (*Clptr)(int);
        Clptr=Code_length;

	int i,rfd,ndc,cfd,x;
	char *Main_array;		
	rfd= Openfileptr("O_RDONLY");
		
		Main_array =  Masterarrayptr(rfd);
		ndc=strlen(Main_array);
		x=Clptr(ndc);
		lseek(rfd,0,SEEK_SET);		
		x-=2;
		if(x<6)
			Compressptr[x](rfd,Main_array);
		else
			printf("Cannot compress further\n");	
	close(rfd);
	return x;
		
	}
