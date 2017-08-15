#include"header.h"
#include"declaration.h"
int Compression3(int fd,char* ma)
{

	printf("%s : Begins\n",__func__);
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
		{
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		byt|=c;

		ret=read(fd,&ch,1);
		if(ret==0)
		{
			
			c|=0x0F;
			c<<=1;
			byt|=c;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=3;
		byt|=c;

		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x03;
			write(cfd,&byt,1);
			byt^=byt;
			byt|=0x01;
			byt<<=7;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=6;
		byt|=c;
		write(cfd,&byt,1);

		byt^=byt;
		c=ch;
		c<<=7;
		byt|=c;


		ret=read(fd,&ch,1);
		if(ret==0)
		{
			c|=0x0F;
			c<<=3;
			byt|=c;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=1;
		byt|=c;

		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x0F;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=4;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x01;
			write(cfd,&byt,1);
			byt|=0x03;
			byt<<=6;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=7;
		byt|=c;
		write(cfd,&byt,1);
		
		byt^=byt;
		c=ch;
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
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=2;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x07;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=5;
		c>>=5;
		byt|=c;
		write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));
	printf("%s : Ends\n",__func__);

	close(efd);
	return cfd;
}
