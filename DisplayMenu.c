#include"header.h"
#include"declaration.h"

char DisplayMenu()
{
	printf("%s: Begins\n",__func__);	
	char choice;
                printf("\t\t-------------Welcome to Multiple Data compression and Encryption ----------------\n");

                printf("\t\t-----------------------------Enter your choice--------------------------------------\n");
                printf("Enter 'c': \t-----------Compression-----------\n");
                printf("Enter 'd': \t-----------Decompression---------\n");
                printf("Enter 'f': \t-----------Compress Further------------------\n");
                printf("Enter 'q': \t-----------Quit------------------\n");
                scanf(" %c",&choice);
	printf("%s: Ends\n",__func__);	
	return choice;
}
