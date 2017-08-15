#include"header.h"
#include"declaration.h"
int Compression2(int fd,char* ma)
{
	printf("Compression 2 begins\n");
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
		byt^=byt;
		c^=c;

		ret=read(fd,&ch,1);
		if(ret==0)
			break;
		i=Findindexptr(ch,ma);
		c=ch;
		c=(char)i;
		c<<=6;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{	
			c|=0x0F;
			c<<=2;
			byt|=c;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		c=ch;
		c=(char)i;
		c<<=6;
		c>>=2;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x0F;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		c=ch;
		c=(char)i;
		c<<=6;
		c>>=4;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x03;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		c=ch;
		c=(char)i;
		c<<=6;
		c>>=6;
		byt|=c;

		write(cfd,&byt,1);

	}

	write(efd,ma,strlen(ma));
	close(efd);
	//return cfd;
}
