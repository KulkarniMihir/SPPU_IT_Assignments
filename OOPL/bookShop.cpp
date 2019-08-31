#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;

class bookShop
{
	private: 
		static int successTransact,failTransact;
		char *title = NULL,*author = NULL,*publisher = NULL;
		float *price = NULL;
		int *stock = NULL;
	public:
		bookShop()
		{
			title = new char[50];
			author = new char[25];
			publisher = new char[25];
			price = new float;
			stock = new int;
		}
		
		void add()
		{
			cin.ignore();
			cout << "Enter Name of Book: ";
			cin.getline(title,50);
			cout << "Enter Name of Author: ";
			cin.getline(author,25);
			cout << "Enter Name of Publisher: ";
			cin.getline(publisher,25);
			cout << "Enter Price of Book: ";
			cin >> *price;
			cout << "Enter Available Stock: ";
			cin >> *stock;
		}
		
		static void bookTransact()
		{
			cout << "Successful Transactions  : " << successTransact << endl;
			cout << "Unsuccessful Transactions: " << failTransact << endl;
		}
		
		void update(char bname[],char aname[],int *flag)
		{
			search(bname,aname,flag);
			if(*flag == 1)
			{
				cout << "Book Found!" << endl;
				cin.ignore();
				cout << "Re-Enter Name of Author: ";
				cin.getline(author,25);
				cout << "Updated Price: ";
				cin >> *price;
				cout << "Updated Stock: ";
				cin >> *stock;
			}
		}
		
		void search(char name[],int *flag,int dummy)
		{
			int cmp;
			if(dummy == 0)
				cmp = strcmp(name,title);
			else if(dummy == 1)
				cmp = strcmp(name,author);
			if(cmp == 0)
				*flag = 1;
			else 
				*flag = 0;
		}	
				
		void search(char bname[],char aname[],int *flag)
		{
			int cmp,cmp1;
			cmp = strcmp(bname,title);
			cmp1 = strcmp(aname,author);
			if((cmp == 0)&&(cmp1 == 0))
				*flag = 1;
			else 
				*flag = 0;
		}	
		
		void purchase(char bname[],char aname[],int *flag)
		{
			int qty;
			search(bname,aname,flag);
			if(*flag == 1)
			{
				cout << "Enter quantity to purchase: ";
				cin >> qty;
				if(qty <= *stock)
				{
					*stock -= qty;
					cout << "Transaction successful!" << endl << "Total Cost: Rs. " << float(qty**price) << endl;
					successTransact += 1;
				}
				else
				{
					cout << "\nGiven quantity of books not in stock. Inconvenience is Regretted." << endl;
					failTransact += 1;
				}
			}
		}
		
		void disp()
		{
			cout << setw(5) << title << setw(22) << author << setw(30) << *price << setw(9) << *stock << endl;
		}
};
int bookShop :: successTransact;
int bookShop :: failTransact;
int main()
{
	bookShop *b[50];
	char bname[50],aname[25];
	int resp,resp2,nb = 0,tot = 0,i,c,n;
	do
	{
		cout << "\n1. Add Books\n2. Update Book Details\n3. Search a Book\n4. Purchase a Book\n5. Display Total Transactions\n6. Display Inventory\n7. Exit\nYour Choice? ";
		cin >> resp;
		switch(resp)
		{
			case 1:	cout << "How many books do you wish to add? ";
				cin >> n;
				tot += n;
				for(i = 0;i < n;i++)
				{
					b[nb] = new bookShop;
					cout << "Book #" << (nb+1) << endl;
					b[nb] -> add();
					nb += 1;
				}
				
				break;
			case 2: cin.ignore();
				cout << "Enter Name of Book: ";
				cin.getline(bname,50);
				cout << "Enter Name of Author: ";
				cin.getline(aname,25);
				cout << endl;
				for(i = 0;i < tot;i++)
				{
					b[i] -> update(bname,aname,&c);
					if(c == 1)
						break;
				}
				if(c != 1)
					cout << "Book Unavailable. Inconvenience is Regretted." << endl;
				break;
			case 3: cin.ignore();
				cout << "\nWhich parameter do you wish to search by?" << endl << "1. Book Name\n2. Author Name\nYour Choice: ";
				cin >> resp2;
				switch(resp2)
				{
					case 1: cin.ignore();
						cout << "Enter Name of Book: ";
						cin.getline(bname,50);
						for(i = 0;i < tot;i++)
						{
							b[i] -> search(bname,&c,0);
							if(c == 1)
								break;
						}
						break;
					case 2: cin.ignore();
						cout << "Enter Name of Author: ";
						cin.getline(aname,25);
						for(i = 0;i < tot;i++)
						{
							b[i] -> search(aname,&c,1);
							if(c == 1)
								break;
						}
						break;
				}
				cout << endl;
				if(c == 1)
				{
					cout << "Book Found!" << endl;
				}
				else 
				{
					cout << "Book Unavailable. Inconvenience is Regretted." << endl;
				}
				break;
			case 4:	cin.ignore();
				cout << "Enter Name of Book: ";
				cin.getline(bname,50);
				cout << "Enter Name of Author: ";
				cin.getline(aname,25);
				cout << endl;
				for(i = 0;i < tot;i++)
				{
					b[i] -> purchase(bname,aname,&c);
					if(c == 1)
						break;
				}
				break;
			case 5: bookShop::bookTransact();
				break;
			case 6: cout << "\nINVENTORY\n" << endl << setw(5) << "Book" << setw(39) << "Author" << setw(30) << "Price" << setw(10) << "Stock" << endl;
				for(i = 0;i < tot;i++)
				{
					b[i] -> disp();
				}
				break;
			case 7: return 0;
		}
	}while(resp != 7);
	return 0;
}
