#include <stdio.h>
#include <stdlib.h>

#define MaxLen 50

typedef struct
{
	int day;
	char month[9];
	int year;
}dob;

struct student
{
	char rno[8]; //starting with STUD001
	char name[50];
	int marks[5];
	float per;
	dob d;
	long long int contactno;
};

void create(int *count)
{
	int i,n,j;
	*count = 0;
	FILE *fp = fopen("abc.bin","w");
	printf("How many records do you wish to create? ");
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		struct student r;
		char dummy[15];
		strcpy(r.rno,"STUD");
		sprintf(dummy,"%03d",*count + 1);
		strcat(r.rno,dummy);
		printf("%s",r.rno);
		r.per = 0;
		printf("\nStudent #%d\n",*count + 1);
		printf("Enter Name of Student: ");
		scanf("\n");
		gets(r.name);
		printf("Enter Date of Birth:\nDay: ");
		scanf("%d",&r.d.day);
		printf("Month: ");
		scanf("%s",r.d.month);
		printf("Year: ");
		scanf("%d",&r.d.year);
		printf("Contact Number: ");
		scanf("%ld",&r.contactno);
		printf("Enter Marks:\n");
		for(j = 0;j < 5;j++)
		{
			scanf("%d",&r.marks[j]);
			r.per += r.marks[j];
		}
		r.per /= 5;
		*count += 1;
		fwrite(&r,sizeof(r),1,fp);
	}
	fclose(fp);
}

void disp(int *count)
{
	int temp;
	int i,j = 0;
	FILE *fp = fopen("abc.bin","r");
	struct student r;
	printf("Sr. No.\t  Roll Number\t     Name of Student\t   Date of Birth\tContact Number\n");
	for(i = 0;i < *count;i++)
	{
		fread(&r,sizeof(r),1,fp);
		printf("%3d\t%10s\t%20s\t %2d %*-s %4d %14ld\n",(j+1),r.rno,r.name,r.d.day,r.d.month,r.d.year,r.contactno);
		j++;
	}
	fclose(fp);
	temp = j;
}

void add(int *count)
{
	int j;
	FILE *fp = fopen("abc.bin","a");
	struct student r;
	char dummy[15];
	strcpy(r.rno,"STUD");
	sprintf(dummy,"%03d",*count + 1);
	strcat(r.rno,dummy);
	printf("%s",r.rno);
	r.per = 0;
	printf("\nStudent #%d\n",*count + 1);
	printf("Enter Name of Student: ");
	scanf("\n");
	gets(r.name);
	printf("Enter Date of Birth:\nDay: ");
	scanf("%d",&r.d.day);
	printf("Month: ");
	scanf("%s",r.d.month);
	printf("Year: ");
	scanf("%d",&r.d.year);
	printf("Contact Number: ");
	scanf("%ld",&r.contactno);
	printf("Enter Marks:\n");
	for(j = 0;j < 5;j++)
	{
		scanf("%d",&r.marks[j]);
		r.per += r.marks[j];
	}
	r.per /= 5;
	*count += 1;
	fwrite(&r,sizeof(r),1,fp);
	fclose(fp);
}

void search(int *count)
{
	char temp[8];
	int i;
	printf("Enter Roll Number: ");
	scanf("%s",temp);
	FILE *fp = fopen("abc.bin","r");
	struct student r;
	for(i = 0;i < *count;i++)
	{
		fread(&r,sizeof(r),1,fp);
		if(!strcmp(r.rno,temp))
		{
			printf("Record Found!\n");
			break;
		}
	}
	if(i == *count)
		printf("Record Unavailable.\n");
	fclose(fp);
}

void modify(int *count)
{
	int i;
	char temp[8];
	printf("Enter Roll Number: ");
	scanf("%s",temp);
	FILE *fp = fopen("abc.bin","r");
	FILE *t = fopen("temp.bin","w");
	struct student r,s;
	for(i = 0;i < *count;i++)
	{
		fread(&r,sizeof(r),1,fp);
		if(!strcmp(r.rno,temp))
		{
			printf("\nRecord Found!\n");
			s = r;
			printf("Enter Name of Student: ");
			scanf("\n");
			gets(s.name);
			printf("Enter Date of Birth:\nDay: ");
			scanf("%d",&s.d.day);
			printf("Month: ");
			scanf("%s",s.d.month);
			printf("Year: ");
			scanf("%d",&s.d.year);
			printf("Contact Number: ");
			scanf("%ld",&s.contactno);
			fwrite(&s,sizeof(s),1,t);
		}
		else
		{
			fwrite(&r,sizeof(r),1,t);
		}
	}
	if(i == *count)
			printf("\nRecord unavailable.\n");
	fclose(fp);
	fclose(t);
	remove("abc.bin");
	rename("temp.bin","abc.bin");
}

void delete(int *count)
{
	int i,flag = 0;
	char temp[8];
	FILE *fp = fopen("abc.bin","r");
	FILE *t = fopen("temp.bin","w");
	struct student r;
	printf("Enter Roll Number: ");
	scanf("%s",temp);
	for(i = 0;i < *count;i++)
	{
		fread(&r,sizeof(r),1,fp);
		if(!strcmp(r.rno,temp))
		{
			printf("\nRecord Found!\n");
			flag = 1;
		}
		else
		{
			fwrite(&r,sizeof(r),1,t);
		}
	}
	if(flag == 1)
	{
		printf("\nRecord Deleted!\n");
		*count -= 1;
	}
	else
	{
		printf("\nRecord Not Found\n");
	}
	fclose(fp);
	fclose(t);
	remove("abc.bin");
	rename("temp.bin","abc.bin");
}

int main(void)
{
	int n,resp,f = 0,dummy,pos;
	char temp[10];
	static int count = 0;
	struct student s[MaxLen];
	do
	{
		printf("\n1. Create Database\n2. Display Database\n3. Add A Record\n4. Search A Record\n5. Modify A Record\n6. Delete A Record\n7. Exit\nYour Choice? ");
		scanf("%d",&resp);
		switch(resp)
		{
			case 1: create(&count);
					break;
			case 2: disp(&count);
					break;
			case 3:	add(&count);
					break;
			case 4: search(&count);
					break;
			case 5: modify(&count);
					break;
			case 6: delete(&count);
					break;
			case 7: break;
			default: printf("Invalid Response! Try again.\n");
					 break;
		}
	}while(resp != 7);
	return EXIT_SUCCESS;
}
