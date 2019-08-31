/*
 ============================================================================
 Name        : set_operations.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void setunion(int[],int[],int,int,int[],int *);
void setintersection(int[],int[],int,int,int[],int*);
void setinput(int[],int,int[]);
void disp(int[],int,int*,int);
void setdiff(int[],int[],int,int,int[],int*);
void symmdiff(int[],int[],int,int,int[],int*);

int main(void) {
	int i,lenA,lenB,resp,*lenC;
	int US[100],setA[50],setB[50],setC[100];
	for(i = 0;i < 100;i++)
	{
		US[i] = i+1;
	}
	printf("Enter size of Set A: ");
	scanf("%d",&lenA);
	setinput(setA,lenA,US);
	printf("Enter size of Set B: ");
	scanf("%d",&lenB);
	setinput(setB,lenB,US);
	do
	{
		disp(setA,lenA,0,0);
		disp(setB,lenB,0,1);
		printf("1. Union \n2. Intersection \n3. Difference \n4. Symmetric Difference \n5. Exit\nYour choice: ");
		scanf("%d",&resp);
		printf("\n");
		switch(resp)
		{

			case 1: setunion(setA,setB,lenA,lenB,setC,&lenC);
					disp(setC,0,&lenC,2);
					break;
			case 2: setintersection(setA,setB,lenA,lenB,setC,&lenC);
					disp(setC,0,&lenC,2);
					break;
			case 3: printf("C = A - B\n");
					setdiff(setA,setB,lenA,lenB,setC,&lenC);
					disp(setC,0,&lenC,2);
					printf("C = B - A\n");
					setdiff(setB,setA,lenB,lenA,setC,&lenC);
					disp(setC,0,&lenC,2);
					break;
			case 4: symmdiff(setA,setB,lenA,lenB,setC,&lenC);
					disp(setC,0,&lenC,2);
					break;
			case 5: break;
			default: printf("Please enter a valid response.");
					 break;
		}
	}while(resp != 5);
	return EXIT_SUCCESS;
}

void setinput(int setA[],int lenA,int US[])
{
	int i,j,n;
	printf("Enter elements of Set: ");
	for(i = 0;i < lenA;i++)
	{
		x: scanf("%d",&setA[i]);
		for(j = 0;j < 100;j++)
		{
			if(setA[i] == US[j])
			{
				break;
			}
		}
		for(n = 0;n < i;n++)
		{
			if(setA[i] == setA[n])
			{
				printf("Duplicate Value. Please Re-enter.\n");
				goto x;
			}
		}
	}
}

void disp(int setA[],int lenA,int *lenC,int k)
{
	int i;
	if(k == 0)
	{
		printf("\nSet A = {");
		for(i = 0;i < lenA;i++)
		{
			printf("%d",setA[i]);
			if(i < (lenA - 1))
			{
				printf(",");
			}
		}
		printf("}");
		printf("\n");
	}
	else if(k == 1)
	{
		printf("Set B = {");
		for(i = 0;i < lenA;i++)
		{
			printf("%d",setA[i]);
			if(i < (lenA - 1))
			{
				printf(",");
			}
		}
	printf("}");
	printf("\n\n");
	}
	else if(k == 2)
	{
		printf("\nSet C = {");
		for(i = 0;i < *lenC;i++)
		{
			printf("%d",setA[i]);
			if(i < (*lenC - 1))
			{
				printf(",");
			}
		}
			printf("}");
			printf("\n\n");
			printf("Press any key to continue.\n");
			getchar();
			getchar();
	}
}

void setunion(int setA[],int setB[],int lenA,int lenB,int setC[],int *lenC)
{
	int count,j,k;

	for(j = 0;j < lenA;j++)
	{
		setC[j] = setA[j];
	}
	for(j = 0;j < lenB;j++)
	{
		count = 0;
		for(k = 0;k < lenA;k++)
		{
			if(setB[j] == setC[k])
			{
				count++;
			}
		}
		if(count == 0)
		{
			setC[lenA++] = setB[j];
		}
	}
	*lenC = lenA;
}

void setintersection(int setA[],int setB[],int lenA,int lenB,int setC[],int* lenC)
{
	int i,j,count = 0;
	for(i = 0;i < lenA;i++)
	{
		for(j = 0;j < lenB;j++)
		{
			if(setA[i] == setB[j])
			{
				setC[count++] = setA[i];
				break;
			}
		}
	}
	*lenC = count;
}

void setdiff(int setA[],int setB[],int lenA,int lenB,int setC[],int* lenC)
{
	int i,j,count,k = 0;
	for(i = 0;i < lenA;i++)
	{
		count = 0;
		for(j = 0;j < lenB;j++)
		{
			if(setA[i] == setB[j])
			{
				count++;
				break;
			}

		}
		if(count == 0)
		{
			setC[k++] = setA[i];
		}
	}
	*lenC = k;
}
void symmdiff(int setA[],int setB[],int lenA,int lenB,int setC[],int* lenC)
{
	int temp1[50],temp2[50];
	int *lentemp1,*lentemp2;
	setdiff(setA,setB,lenA,lenB,temp1,&lentemp1);
	setdiff(setB,setA,lenB,lenA,temp2,&lentemp2);
	setunion(temp1,temp2,lentemp1,lentemp2,setC,lenC);
}
