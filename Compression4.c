#include"header.h"
#include"declaration.h"

int Compression4(int fd,char* ma)
{
	printf("%s: Begins\n",__func__);
	unsigned char c,byt; char ch;
	int cfd,efd,i,ret;
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;
	int (*Findindexptr)(char,char*);
	Findindexptr=Find_Index;
	printf("opening Compressed file\n");
	cfd=Openfileptr("O_RDWR");
	printf("open Encryption file\n");
	efd=Openfileptr("O_WRONLY");
	
	while(1)
	{
		
		byt=byt^byt;
		c=c^c;
		
		ret=read(fd,&ch,1);

		if(ret==0)
			break;
		i=Findindexptr(ch,ma);
		printf("%d\n",i);		
		c=(char)i;
		c=c<<4;
	
		byt=byt|c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0X0F;	
			write(cfd,&byt,1);		
			break;
		}
		i=Findindexptr(ch,ma);
		printf("%d\n",i);		
		c=(char)i;
		
		c=c<<4;
		c=c>>4;
		
		byt=byt|c;
		
		write(cfd,&byt,1);	
	}
		
		write(efd,ma,strlen(ma));
		
	
	printf("%s: Ends\n",__func__);
	
	close(efd);
	return cfd;
}
