#include"header.h"
#include"declaration.h"
int Decompression2(int cfd,char* ekey)
{
	printf("%s: Begins",__func__);
	int (*Openfileptr)(char*);
	Openfileptr=Open_File;

	unsigned char c; char ch;
	int dfd,i;

	printf("Enter Decompressed file\n");
	dfd=Openfileptr("O_WRONLY");
	
	while(1)
	{
		c^=c;

		if(read(cfd,&ch,1)==0)
			break;
		c=ch;
		c>>=6;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=2;
		c>>=4;
		if(c==0x0F)
			break;
		c>>=2;
		i=(int)c;
		write(dfd,(ekey+i),1);

		c=ch;
		c<<=4;
		c>>=4;
		if(c==0x0F)
			break;
		c>>=2;
		i=(int)c;
		write(dfd,(ekey+i),1);
			
		c=ch;
		c<<=6;
		c>>=6;
		if(c==0x03)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
	}
	printf("%s: Ends",__func__);
	close(dfd);	
}
