#include"header.h"
#include"declaration.h"

int Find_Index(char ch,char *ma)
{
	int len,i;
	len=strlen(ma);
	for(i=0;i<len;i++)
	{
		if(ch==*(ma+i))
			return i;
	}

	printf("Fileindex function ends\n");
	exit(EXIT_FAILURE);
	
}	
		
