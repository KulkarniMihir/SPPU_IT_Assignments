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
	int flag;
	char name[50];
	int marks[5];
	float per;
	dob d;
	long long int contactno;
};

void add(struct student *p,int n,int pos,int *count)
{
	int i,j;
	if(pos == 0)
	{
		for(i = 0;i < n;i++)
		{
			char dummy[15];
			strcpy(p[*count].rno,"STUD");
			sprintf(dummy,"%03d",*count + 1);
			strcat(p[*count].rno,dummy);
			printf("%s",p[*count].rno);
			p[*count].per = 0;
			printf("\nStudent #%d\n",*count + 1);
			printf("Enter Name of Student: ");
			scanf("\n");
			gets(p[*count].name);
			printf("Enter Date of Birth:\nDay: ");
			scanf("%d",&p[*count].d.day);
			printf("Month: ");
			scanf("%s",p[*count].d.month);
			printf("Year: ");
			scanf("%d",&p[*count].d.year);
			printf("Contact Number: ");
			scanf("%ld",&p[*count].contactno);
			printf("Enter Marks:\n");
			for(j = 0;j < 5;j++)
			{
				scanf("%d",&p[*count].marks[j]);
				p[*count].per += p[*count].marks[j];
			}
			p[*count].per /= 5;
			p[*count].flag = 1;
			*count += 1;
		}
	}
	else
	{
		struct student temp2;
		char dummy[15];
		strcpy(temp2.rno,"STUD");
		sprintf(dummy,"%03d",*count + 1);
		strcat(temp2.rno,dummy);
		printf("%s",temp2.rno);
		temp2.per = 0;
		printf("\nStudent #%d\n",count + 1);
		printf("Enter Name of Student: ");
		scanf("\n");
		gets(temp2.name);
		printf("Enter Date of Birth:\nDay: ");
		scanf("%d",&temp2.d.day);
		printf("Month: ");
		scanf("%s",temp2.d.month);
		printf("Year: ");
		scanf("%d",&temp2.d.year);
		printf("Contact Number: ");
		scanf("%ld",&temp2.contactno);
		printf("Enter Marks:\n");
		for(j = 0;j < 5;j++)
		{
			scanf("%d",&temp2.marks[j]);
			temp2.per += temp2.marks[j];
		}
		temp2.per /= 5;
		temp2.flag = 1;
		p[*count] = p[pos];
		p[pos] = temp2;
		*count += 1;
	}
}

void disp(struct student *p,int *count)
{
	int temp1;
	int i,j = 0;
	printf("\tSr. No.\t\tRoll Number\tName of Student\t\tDate of Birth\t\tContact Number\n");
	for(i = 0;i < *count;i++)
	{
		if(p[i].flag != 0)
		{
			printf("\t  %d\t\t    %s\t\t     %s\t\t%d  %s  %d  %ld\n",(j+1),p[i].rno,p[i].name,p[i].d.day,p[i].d.month,p[i].d.year,p[i].contactno);
			j++;
		}
	}
	temp1 = j;
}

void sort(struct student *a,int n)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = i + 1;j < n;j++)
		{
			if(a[j].per > a[i].per)
			{
				struct student t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
}

void dispresult(struct student *p,int *count)
{
	int i,j;
	sort(p,*count);
	printf("Rank\tName\t\tPercentage\n");
	for(j = 0;j < 3;j++)
	{
		printf("%d\t%s\t  %.2f\n",(j+1),p[j].name,p[j].per);
	}
}

void search(struct student *p,char *r,int *f,int *loc,int *count)
{
	int i;
	for(i = 0;i < *count;i++)
	{
		if(!strcmp(p[i].rno,r))
		{
			printf("\nRecord Found!\n");
			*f = 1;
			*loc = i;
			break;
		}
	}
	if(i == *count)
		printf("\nRecord Unavailable.\n");
}

void modify(struct student *p,char *r,int *count)
{
	int f,loc;
	search(p,r,&f,&loc,&count);
	if(f == 1)
	{
		printf("\nModifications:\n");
		printf("Enter Name of Student: ");
		scanf("\n");
		gets(p[loc].name);
		printf("Contact Number: ");
		scanf("%ld",&p[loc].contactno);
	}
}

void delete(struct student *p,char *r,int *count)
{
	int f,loc;
	search(p,r,&f,&loc,&count);
	p[loc] = p[*count - 1];
	if(f == 1)
	{
		p[*count-1].flag = 0;
		printf("\nRecord Deleted.\n");
	}
}

int main(void) {
	int n,resp,f = 0,dummy,pos;
	char temp[10];
	static int count = 0;
	struct student s[MaxLen];
	do
	{
		printf("\n1. Create Database\n2. Display Database\n3. Add A Record\n4. Search A Record\n5. Modify A Record\n6. Delete A Record\n7. Display Rankers\n8. Exit\nYour Choice? ");
		scanf("%d",&resp);
		switch(resp)
		{
			case 1: printf("How many records do you wish to create? ");
					scanf("%d",&n);
					add(s,n,0,&count);
					break;
			case 2: disp(s,&count);
					break;
			case 3:	printf("Which position do you wish to add a record? ");
					scanf("%d",&pos);
					if(pos < count)
						add(s,1,pos,&count);
					else
						printf("\nInvalid Position.\n;");
					break;
			case 4: printf("Enter Roll Number: ");
					scanf("%s",temp);
					search(s,temp,&f,&dummy,&count);
					break;
			case 5: printf("Enter Roll Number: ");
					scanf("%s",temp);
					modify(s,temp,&count);
					break;
			case 6: printf("Enter Roll Number: ");
					scanf("%s",temp);
					delete(s,temp,&count);
					break;
			case 7: dispresult(s,&count);
					break;
			case 8: break;
			default: printf("Invalid Response! Try again.\n");
					 break;
		}
	}while(resp != 8);
	return EXIT_SUCCESS;
}
