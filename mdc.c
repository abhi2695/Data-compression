# include"header.h"
#include"declaration.h"
int main()
{	
	char (*Displaymenuptr)();
	Displaymenuptr=DisplayMenu;
	int (*Compressfurtherptr)(int);
	Compressfurtherptr=Compressfurther;
	int (*Choiceptr[])()= {Compression,Decompression};
	int choice,x,y,cl,cfd;
	while(1)
	{
		choice=Displaymenuptr();

		{	
		switch(choice)
		{
		case 'c':
			cl=Choiceptr[0]();
			break;
		case 'd':
			Choiceptr[1]();
			break;
		case 'q':
			exit(EXIT_SUCCESS);
			break;
		case 'f':
			Compressfurtherptr(cl);
			break;
		default:
			printf("Enter a valid no\n");
			break;
		}

	}
 

}

 return 0;
}


		
		
