#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	char c;
	FILE *fp1,*fp2;
	if((argc == 3)&&(!strcmp(argv[1],"TYPE")))
	{
		fp1 = fopen(argv[2],"r");
		while((c = getc(fp1)) != EOF)
		{
			printf("%c",c);
		}
		fclose(fp1);
	}
	else if((argc == 4)&&(!strcmp(argv[1],"COPY")))
	{
		fp1 = fopen(argv[2],"r");
		fp2 = fopen(argv[3],"w+");
		printf("\nCopy Successful!\n");
		while((c = getc(fp1)) != EOF)
		{
			putc(c,fp2);
		}
		rewind(fp1);
		rewind(fp2);
		printf("\nDestination File: \n");
		while((c = getc(fp1)) != EOF)
		{
			printf("%c",c);
		}
		printf("\nSource File: \n");
		while((c = getc(fp2)) != EOF)
		{
			printf("%c",c);
		}
		fclose(fp1);
		fclose(fp2);
	}
	else
		printf("\nInvalid Arguments Passed.\n");
	return EXIT_SUCCESS;
}
