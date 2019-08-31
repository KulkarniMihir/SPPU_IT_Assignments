#include <stdio.h>
#include <stdlib.h>

#define maxLEN 100

int str_len(char*);
void str_rev(char[],int);
int str_cmp(char[],int,char[],int);
void str_cpy(char*,char*,int);
int str_sub(char[],char[],int,int);

int main(void) {
	int resp,L1,L2,flag1;
	char str[maxLEN],dest[maxLEN],src[maxLEN];
	do
	{
		printf("\n1. Find Length of String\n2. Compare 2 Strings\n3. Copy String\n4. Reverse String\n5. Check if String is a Palindrome\n6. Check Substring\n7. Exit\nYour Choice? ");
		scanf("%d",&resp);
		switch(resp)
		{
			case 1: printf("Enter a string whose length you wish to find: ");
					scanf("\n");
					gets(str);
					L1 = str_len(str);
					printf("\nLength of the given string is: %d\n\n",L1);
					break;
			case 2: printf("Enter String #1: ");
					scanf("\n");
					gets(dest);
					L1 = str_len(dest);
					printf("Enter String #2: ");
					scanf("\n");
					gets(src);
					L2 = str_len(src);
					if(L1 > L2)
						flag1 = str_cmp(dest,L1,src,2);
					else
						flag1 = str_cmp(src,L2,dest,1);
					if(flag1 == 0)
						printf("\nStrings '%s' and '%s' are equivalent.\n",dest,src);
					else if(flag1 == -1)
						printf("\nString '%s' is alphabetically ahead of string '%s'.\n",dest,src);
					else if(flag1 == 1)
						printf("\nString '%s' is alphabetically ahead of string '%s'.\n",src,dest);
					break;
			case 3: printf("Enter String #1: ");
					scanf("\n");
					gets(dest);
					L1 = str_len(dest);
					printf("Enter String #2: ");
					scanf("\n");
					gets(src);
					L2 = str_len(src);
					str_cpy(dest,src,L2);
					printf("\nString #1: '%s'\nString #2: '%s'\n",dest,src);
					break;
			case 4: printf("Enter a string you wish to reverse: ");
					scanf("\n");
					gets(str);
					printf("\nOriginal String: %s\n",str);
					L1 = str_len(str);
					str_rev(str,L1);
					printf("Reversed String: %s\n",str);
					break;
			case 5: printf("\nEnter a string you wish to check: ");
					scanf("\n");
					gets(str);
					L1 = str_len(str);
					str_cpy(dest,str,L1);
					str_rev(str,L1);
					flag1 = str_cmp(dest,L1,str,1);
					if(flag1 == 0)
						printf("\nString '%s' is a palindrome.\n",dest);
					else
						printf("\nString '%s' is not a palindrome.\n",dest);
					break;
			case 6: printf("Enter String #1: ");
					scanf("\n");
					gets(dest);
					L1 = str_len(dest);
					printf("Enter String #2: ");
					scanf("\n");
					gets(src);
					L2 = str_len(src);
					flag1 = str_sub(dest,src,L1,L2);
					if(flag1 != 0)
						printf("\nString '%s' is a substring of '%s'\n",src,dest);
					else
						printf("\nString '%s' is NOT a substring of '%s'\n",src,dest);
					break;
			case 7: break;
			default: printf("Please enter a valid response.");

		}
	}while(resp != 7);
	return EXIT_SUCCESS;
}

int str_len(char *str)
{
	int i,count=0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void str_rev(char str[],int L)
{
	int i;
	char temp1[maxLEN];
	for(i = 0;i < L;i++)
		temp1[i] = str[L - i - 1];
	for(i = 0;i < L;i++)
		str[i] = temp1[i];
	str[L] = '\0';
}

int str_cmp(char dest[],int L,char src[],int j)
{
	int i;
	if(j == 1)
	{
		for(i = 0;i < L;i++)
		{
			if(dest[i] > src[i])
				return 1;
			else if(dest[i] < src[i])
				return -1;
			else if(dest[i] == src[i])
				continue;
		}
		return 0;
	}
	else if(j == 2)
	{
		for(i = 0;i < L;i++)
		{
			if(dest[i] > src[i])
				return -1;
			else if(dest[i] < src[i])
				return 1;
			else if(dest[i] == src[i])
				continue;
		}
		return 0;
	}
}

void str_cpy(char *dest,char *src,int L)
{
	int i;
	for(i = 0;i < L;i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
}

int str_sub(char dest[],char src[],int L1,int L2)
{
	int i,j,temp = 0;
	if(L2 > L1)
		return 0;
	else
	{
		for(i = 0;i < (L1 - L2);i++)
		{
			for(j = i;j < (i + L2);j++)
			{
				temp = 1;
				if(dest[j] != src[j - i])
				{
					temp = 0;
					break;
				}
			}
			if(temp == 1)
				break;
		}
		return temp;
	}
}

int str_sub(char dest[],char src[],int L1,int L2)
{
	int i,j,temp = 0;
	if(L2 > L1)
		return 0;
	else
	{

	}
}
