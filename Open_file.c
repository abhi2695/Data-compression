#include"header.h"
#include"declaration.h"

int Open_File(char *mode)
{
	char *file;
	int fd;


		file=(char *)malloc(sizeof(char)*20);
		if(!file)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		printf("Enter the file name\n");
		scanf("%s",file);

		if(strncmp("O_RDONLY",mode,8)==0)		
		{	
			fd=open(file,O_RDONLY);
		}
		if(strncmp("O_WRONLY",mode,8)==0)
		{		
			fd=open(file,O_WRONLY|O_CREAT);
		}
		if(strncmp("O_RDWR",mode,6)==0)	
		{
			fd=open(file,O_RDWR|O_CREAT);
		}
		if(fd==-1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
	return fd;
}	
		
