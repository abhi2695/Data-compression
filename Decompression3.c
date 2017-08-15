#include"header.h"
#include"declaration.h"
int Decompression3(int cfd,char* ekey)
{
	printf("%s: Begins\n",__func__);
	int (*Openfileptr)(char*);
        Openfileptr=Open_File;

	unsigned char c,x; char ch;
	int i,dfd;

	printf("Enter Decompressed file\n");
	dfd=Openfileptr("O_WRONLY");
	while(1)
	{	
		x^=x;
		if(read(cfd,&ch,1)==0)
			break;
	
		c^=c;
		c=ch;
		c>>=5;
		i=(int)c;
		write(dfd,(ekey+i),1);
			
		c=ch;
		c<<=3;
		c>>=5;
		if(c==0x07)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
			
		c=ch;
		c<<=6;
		c>>=5;
		
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=7;
		c|=x;
		if(c==0x07)
			break;
		i=(int)c;	
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=1;
		c>>=5;
		if(c==0x07)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=4;
		c>>=5;
		if(c==0x07)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=7;
		c>>=5;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=6;
		c|=x;
		if(c==0x07)
			break;
		i=(int)c;	
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=2;
		c>>=5;
		if(c==0x07)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=5;
		c>>=5;
		if(c==0x07)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
	}
	printf("%s: Ends\n",__func__);
	close(dfd);
}
