#! /bin/bash

mdc: mdc.o Compressfurther.o Compression.o Decompression.o DisplayMenu.o Open_file.o Create_Master_Array.o Compression2.o Compression3.o Compression4.o Compression5.o Compression6.o Compression7.o Code_length.o  Findindex.o Decompression2.o Decompression3.o Decompression4.o Decompression5.o Decompression6.o Decompression7.o
	gcc -o  mdc mdc.o Compressfurther.o Compression.o Decompression.o DisplayMenu.o Open_file.o Create_Master_Array.o Compression2.o Compression3.o Compression4.o Compression5.o Compression6.o Compression7.o Code_length.o  Findindex.o Decompression2.o Decompression3.o Decompression4.o Decompression5.o Decompression6.o Decompression7.o
mdc.o: mdc.c declaration.h header.h 
	gcc -c mdc.c 
Compression.o: Compression.c declaration.h header.h 
	gcc -c Compression.c 
Compressfurther.o: Compressfurther.c declaration.h header.h 
	gcc -c Compressfurther.c 
Decompression.o: Decompression.c declaration.h header.h 
	gcc -c Decompression.c 
DisplayMenu.o: DisplayMenu.c declaration.h header.h 
	gcc -c DisplayMenu.c 
Open_file.o: Open_file.c declaration.h header.h 
	gcc -c Open_file.c 
Create_Master_Array.o: Create_Master_Array.c declaration.h header.h 
	gcc -c Create_Master_Array.c 
Compression2.o: Compression2.c declaration.h header.h 
	gcc -c Compression2.c 
Compression3.o: Compression3.c declaration.h header.h 
	gcc -c Compression3.c 
Compression4.o: Compression4.c declaration.h header.h 
	gcc -c Compression4.c 
Compression5.o: Compression5.c declaration.h header.h 
	gcc -c Compression5.c 
Compression6.o: Compression6.c declaration.h header.h 
	gcc -c Compression6.c 
Compression7.o: Compression7.c declaration.h header.h 
	gcc -c Compression7.c 
Code_length.o: Code_length.c declaration.h header.h 
	gcc -c Code_length.c 
Findindex.o: Findindex.c declaration.h header.h 
	gcc -c Findindex.c 
Decompression2.o: Decompression2.c declaration.h header.h 
	gcc -c Decompression2.c 
Decompression3.o: Decompression3.c declaration.h header.h 
	gcc -c Decompression3.c 
Decompression4.o: Decompression4.c declaration.h header.h 
	gcc -c Decompression4.c 
Decompression5.o: Decompression5.c declaration.h header.h 
	gcc -c Decompression5.c 
Decompression6.o: Decompression6.c declaration.h header.h 
	gcc -c Decompression6.c 
Decompression7.o: Decompression7.c declaration.h header.h 
	gcc -c Decompression7.c 


clean:
	rm *.o
	rm mdc
clean1:
	rm CF*
	rm EF*
	rm DF*
