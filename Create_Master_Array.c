# include"header.h"
#include"declaration.h"
	char *Create_Master_Array(int rfd)
	{
	char *Main_array,ch;
	int i=0,j,ret,flag=0,x=0,e;	
	Main_array=NULL;	
	e=lseek(rfd,0,SEEK_END);
	lseek(rfd,0,SEEK_SET);
	for(x=0;x<e;x++)
	{
		ret=read(rfd,&ch,1);
		if(ret==-1)
		{
			perror("read");
			close(rfd);
			exit(EXIT_FAILURE);
		}
		if(ret==0)
		{
			break;
		}
		if(i>0)
		{
			for(j=0;j<=i;j++)
			{
			
				if(*(Main_array+j)==ch)
				flag=1;
			}
		}	
	
			if(flag==0)
			{
				Main_array= (char *)realloc(Main_array,i+1);
				if(!Main_array)
				{
					perror("realloc");
					exit(EXIT_FAILURE);					
				}
				*(Main_array+i)=ch;
				i++;
			}
			else 
			 flag=0;
		}	 
		*(Main_array+i)='\0';	
		
	
 return Main_array;	
	}
