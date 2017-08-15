#include"header.h"
#include"declaration.h"
int Decompression4(int cfd,char *ekey)
{
	printf("%s: Begins\n",__func__);
	int (*Openfileptr)(char*);
        Openfileptr=Open_File;

 	 unsigned char c;char ch;
	int dfd, i;
	printf("Enter the Decompressed file\n");
	dfd=Openfileptr("O_WRONLY");
	while(1)
	{
		if(read(cfd,&ch,1)==0)
		{	
			break;
		}
		c^=c;
		c=ch;
		
		c=c>>4;
		i=(int)c;
		
		
		write(dfd,(ekey+i),1);
		c^=c;
		c=ch;
		
		c=c<<4;
		c=c>>4;
		if(c==0x0F)
			break;
		i=(int)c;
		
		
		write(dfd,(ekey+i),1);
	}
	close(dfd);
	printf("%s: Ends\n",__func__);
}
