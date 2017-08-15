#include"header.h"
#include"declaration.h"
int Decompression6(int cfd,char* ekey)
{
	printf("%s: Begins\n",__func__);
	int (*Openfileptr)(char*);
        Openfileptr=Open_File;

         unsigned char c,x;char ch;
        int dfd, i;
        printf("Enter the Decompressed file\n");
        dfd=Openfileptr("O_WRONLY");
        while(1)
	{
		c^=c;
		x^=x;
		if(read(cfd,&ch,1)==0)
			break;
		c=ch;
		c>>=2;
		i=(int)c;
		write(dfd,(ekey+i),1);

		c=ch;
		c<<=6;
		c>>=2;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=4;
		c|=x;
		if(c==0x3F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);

		c=ch;
		c<<=4;
		c>>=2;
		if(read(cfd,&ch,1)==0)
			break;
		x=ch;
		x>>=6;
		c|=x;
		if(c==0x3F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		
		c=ch;
		c<<=2;
		c>>=2;
		if(c==0x3F)
			break;
		i=(int)c;
		write(dfd,(ekey+i),1);
		}	

	printf("%s: Ends\n",__func__);
}
