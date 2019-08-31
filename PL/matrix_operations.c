#include <stdio.h>
#include <stdlib.h>

void inpMat(int[][10],int,int);
void dispMat(int[][10],int,int);
void addMat(int[][10],int[][10],int[][10],int,int);
void mulMat(int[][10],int[][10],int[][10],int,int,int);
void transMat(int[][10],int[][10],int,int);
void saddlept(int[][10],int,int);
void inpMat1(int*,int,int);
void dispMat1(int*,int,int);
void addMat1(int*,int*,int*,int,int);
void mulMat1(int*,int*,int*,int,int,int);
void transMat1(int*,int*,int,int);
void saddlept1(int*,int,int);

int main(void) {
	int resp,r1,c1,r2,c2,r3,c3;
	int A[10][10],B[10][10],C[10][10];
	do
	{
		printf("\n1. Add 2 Matrices\n2. Multiply 2 Matrices\n3. Transpose of a Matrix\n4. Saddle Point of a Matrix\n5. Display Matrix\n6. Exit\nYour Choice: ");
		scanf("%d",&resp);
		switch(resp)
		{
			case 1: printf("Matrix A:\nEnter Number of Rows: ");
					scanf("%d",&r1);
					printf("Enter Number of Columns: ");
					scanf("%d",&c1);
					inpMat(A,r1,c1);
					printf("Matrix B:\nEnter Number of Rows: ");
					scanf("%d",&r2);
					printf("Enter Number of Columns: ");
					scanf("%d",&c2);
					inpMat(B,r2,c2);
					if((r1 == r2) && (c1 == c2))
						{
							r3 = r1;
							c3 = c1;
							addMat(A,B,C,r3,c3);
							break;
						}
					else
					{
						printf("Addition not possible.\n");
					}
					break;
			case 2: printf("Matrix A:\nEnter Number of Rows: ");
					scanf("%d",&r1);
					printf("Enter Number of Columns: ");
					scanf("%d",&c1);
					inpMat(A,r1,c1);
					printf("Matrix B:\nEnter Number of Rows: ");
					scanf("%d",&r2);
					printf("Enter Number of Columns: ");
					scanf("%d",&c2);
					inpMat(B,r2,c2);
					if(c1 == r2)
					{
						r3 = r1;
						c3 = c2;
						mulMat(A,B,C,r3,c3,r2);
						break;
					}
					else
					{
						printf("Multiplication not possible.\n");
					}
					break;
			case 3: printf("Matrix:\nEnter Number of Rows: ");
					scanf("%d",&r1);
					printf("Enter Number of Columns: ");
					scanf("%d",&c1);
					inpMat(A,r1,c1);
					transMat(A,C,r1,c1);
					r3 = c1;
					c3 = r1;
					break;
			case 4: printf("Matrix:\nEnter Number of Rows: ");
					scanf("%d",&r3);
					printf("Enter Number of Columns: ");
					scanf("%d",&c3);
					inpMat(C,r3,c3);
					saddlept(C,r3,c3);
					break;
			case 5: dispMat(C,r3,c3);
					break;
			case 6: break;
			default: printf("Please enter a valid response.");
					 break;
		}
	}while(resp != 6);
	return EXIT_SUCCESS;
}

//*********Functions Without Pointers

void inpMat(int A[][10],int r,int c)
{
	int i,j;
	for(i = 0;i < r;i++)
	{
		printf("Enter elements of Row #%d: ",i + 1);
		for(j = 0;j < c;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
}

void dispMat(int C[][10],int r,int c)
{
	int i,j;
	for(i = 0;i < r;i++)
	{
		printf("|");
		for(j = 0;j < c;j++)
		{
			if(j == c-1)
			{
				printf("%d|",C[i][j]);
			}
			else
			{
				printf("%d\t",C[i][j]);
			}
		}
		printf("\n");
	}
}

void addMat(int A[][10],int B[][10],int C[][10],int r,int c)
{
	int i,j;
	for(i = 0;i < r;i++)
	{
		for(j = 0;j < c;j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void mulMat(int A[][10],int B[][10],int C[][10],int r,int c,int d)
{
	int i,j,k,temp;
	for(i = 0;i < r;i++)
	{
		for(k = 0;k < c;k++)
		{
			temp = 0;
			for(j = 0;j < d;j++)
			{
				temp += A[i][j] * B[j][k];
			}
			C[i][k] = temp;
		}
	}
}

void transMat(int A[][10],int C[][10],int r,int c)
{
	int i,j;
	for(i = 0;i < c;i++)
	{
		for(j = 0;j < r;j++)
		{
			C[i][j] = A[j][i];
		}
	}
}

void saddlept(int A[][10],int r,int c)
{
	int i,j,k;
	for(i = 0;i < r;i++)
	{
		int min_row = A[i][0], col_ind = 0;
	    for (j = 1; j < c; j++)
	    {
	    	if (min_row > A[i][j])
	        {
	    		min_row = A[i][j];
	            col_ind = j;
	        }
	    }
	    for(k = 0; k < r; k++)
	    	if (min_row < A[k][col_ind])
	    		break;
	    if (k == r)
	    {
	    	printf("Value of Saddle Point is %d present at [%d][%d]\n",min_row,(k-1),col_ind);
	    }
	}
}

//*******Functions With Pointers

void inpMat1(int *A,int r,int c)
{
	int i,j;
		for(i = 0;i < r;i++)
		{
			printf("Enter elements of Row #%d: ",i + 1);
			for(j = 0;j < c;j++)
			{
				scanf("%d",(A + (i*c) + j));
			}
		}
}

void dispMat1(int *C,int r,int c)
{
	int i,j;
	for(i = 0;i < r;i++)
	{
		printf("|");
		for(j = 0;j < c;j++)
		{
			if(j == c-1)
			{
				printf("%d|",*(C +(i*c) + j));
			}
			else
			{
				printf("%d\t",*(C +(i*c) + j));
			}
		}
		printf("\n");
	}
}

void addMat1(int *A,int *B,int *C,int r,int c)
{
	int i,j;
	for(i = 0;i < r;i++)
	{
		for(j = 0;j < c;j++)
		{
			*(C +(i*c) + j) = (*(A +(i*c) + j) + *(B +(i*c) + j));
		}
	}
}

void mulMat1(int *A,int *B,int *C,int r,int c,int d)
{
	int i,j,k;
	for(i = 0;i < r;i++)
	{
		for(k = 0;k < c;k++)
		{
			for(j = 0;j < d;j++)
			{
				*(C +(i*c) + j) += (*((A +(i*c) + j)) * (*(B +(j*r) + i)));
			}
		}
	}
}

void transMat1(int *A,int *C,int r,int c)
{
	int i,j;
	for(i = 0;i < c;i++)
	{
		for(j = 0;j < r;j++)
		{
			*(C +(i*c) + j) = *(A +(j*r) + i);
		}
	}
}

void saddlept1(int *A,int r,int c)
{
	int i,j,k;
	for(i = 0;i < r;i++)
	{
		int min_row = *(A +(i*c)), col_ind = 0;
	    for (j = 1; j < c; j++)
	    {
	    	if (min_row > *(A +(i*c) + j))
	        {
	    		min_row = *(A +(i*c) + j);
	            col_ind = j;
	        }
	    }
	    for(k = 0; k < r; k++)
	    	if (min_row < *(A +(k*c) + col_ind))
	    		break;
	    if (k == r)
	    {
	    	printf("Value of Saddle Point is %d\n",min_row);
	    }
	}
}
