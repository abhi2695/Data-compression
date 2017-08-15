#include"header.h"
#include"declaration.h"
int Compression5(int fd,char* ma)
{
	printf("%s: Begins\n",__func__);
	unsigned char c,byt, ch;
	int cfd,efd,ret,i;
	
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;
	int(*Findindexptr)(char,char*);
	Findindexptr=Find_Index;
	
	printf("Enter compressed file \n");
	cfd=Openfileptr("O_RDWR");
	printf("Enter Encryption key \n");
	efd=Openfileptr("O_WRONLY");
		
	while(1)
	{	
		byt^=byt;
		c^=c;
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x1F;
			byt<<=3;
			write(cfd,&byt,1);
			break;
		}
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		byt|=c;

		ret=read(fd,&ch,1);
		if(ret==0)
		{	
			byt|=0x07;
			write(cfd,&byt,1);
			byt^=byt;
			byt|=0x03;
			byt<<=6;
			write(cfd,&byt,1);
			break;
		}	
	
		i=Findindexptr(ch,ma);
		
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=5;
		byt|=c;
		write(cfd,&byt,1);

		byt^=byt;
		c=ch;
		c<<=6;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{	
			c|=0x1F;
			c<<=1;
			byt|=c;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=2;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{	
			byt|=0x01;
			write(cfd,&byt,1);
			byt^=byt;
			byt|=0x0F;
			byt<<=4;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=7;
		byt|=c;
		write(cfd,&byt,1);
		
		byt^=byt;
		c=ch;
		c<<=4;
		byt|=c;

		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x0F;
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
		c<<=3;
		c>>=4;
		byt|=c;
		write(cfd,&byt,1);
		
		byt^=byt;
		c=ch;
		c<<=7;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			c|=0x1F;
			c<<=2;
			byt|=c;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=1;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x03;
			write(cfd,&byt,1);
			byt^=byt;
			byt|=0x07;
			byt<<=5;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=6;
		byt|=c;
		write(cfd,&byt,1);
		
		byt^=byt;
		c=ch;
		c<<=5;
		byt|=c;
		
		ret=read(fd,&ch,1);
		if(ret==0)
		{
			byt|=0x1F;
			write(cfd,&byt,1);
			break;
		}	
		i=Findindexptr(ch,ma);
		ch=(char)i;
		c=ch;
		c<<=3;
		c>>=3;
		byt|=c;
		write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));
	
	close(efd);
	printf("%s: Ends\n",__func__);
//	return cfd;
}
