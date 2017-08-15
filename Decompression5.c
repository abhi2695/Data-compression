#include"header.h"
#include"declaration.h"
int Decompression5(int cfd,char* ekey)
{

	printf("%s: Begins\n",__func__);
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;

	unsigned char c,x; char ch;
	int dfd,i;

	printf("Enter Decompressed file\n");
	dfd=Openfileptr("O_WRONLY");

	while(1)
	{
		c^=c;
		x^=x;
		if(read(cfd,&ch,1)==0)
			break;
		c=ch;
		c>>=3;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=5;
		c>>=3;
		x=c;
		if(read(cfd,&ch,1)==0)
			break;
		c^=c;
		c=ch;
		c>>=6;
		c|=x;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);

		c=ch;
		c<<=2;
		c>>=3;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);

		c=ch;
		c<<=7;
		c>>=3;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=4;
		c|=x;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);	
		
		c=ch;
		c<<=4;
		c>>=3;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=7;
		c|=x;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);	

		c=ch;
		c<<=1;
		c>>=3;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);	
		
		c=ch;
		c<<=6;
		c>>=3;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=5;
		c|=x;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);	
		
		c=ch;
		c<<=3;
		c>>=3;
		if(c==0x1F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);	
	}
	close(dfd);		
	printf("%s: Ends\n",__func__);

}
