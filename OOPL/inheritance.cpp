#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class base1
{
	protected:
		char *name,*bg;
		long int *dob;
	public:
		base1()
		{
			name = new char[50];
			bg = new char[3];
			dob = new long int;
		}

};

class base2
{
	protected:
		float *height,*weight;
	public:
		base2()
		{
			height = new float;
			weight = new float;
		}
};

class base3
{
	protected:
		char *policyno,*address;
	public:
		base3()
		{
			policyno = new char[12];
			address = new char[100];
		}
};

class derived:public base1, public base2, public base3
{	
	protected:
		long int *telno;
		char *driverno;
		static int count;
	public:
		derived()
		{
			telno = new long int;
			driverno = new char[15];
		}
		void add();
		void disp();
		void search(char*,int*);
		void update();
		static void delrec()
		{
			count -= 1;
		}
};

int derived::count;

void derived::add()
{
	cin.ignore();
	cout << "Enter Name: ";
	cin.getline(name,50);
	cout << "Enter Date of Birth (DDMMYYYY): ";
	cin >> *dob;
	cin.ignore();
	cout << "Enter Blood Group: ";
	cin.getline(bg,3);
	cout << "Enter Height: ";
	cin >> *height;
	cout << "Enter Weight: ";
	cin >> *weight;
	cin.ignore();
	cout << "Enter Policy Number: ";
	cin.getline(policyno,12);
	cout << "Enter Locality: ";
	cin.getline(address,100);
	cout << "Enter Telephone Number: ";
	cin >> *telno;
	cin.ignore();
	cout << "Enter Driving License Number: ";
	cin.getline(driverno,15);
	count += 1;
}

void derived::search(char temp[],int *c)
{
	if(!strcmp(driverno,temp))
		*c = 1;
}

void derived::update()
{
	cin.ignore();
	cout << "Re-enter Name: ";
	cin.getline(name,50);
	cout << "Re-enter Date of Birth (DDMMYYYY): ";
	cin >> *dob;
	cin.ignore();
	cout << "Re-enter Blood Group: ";
	cin.getline(bg,3);
	cout << "Re-enter Height: ";
	cin >> *height;
	cout << "Re-enter Weight: ";
	cin >> *weight;
	cin.ignore();
	cout << "Re-enter Locality: ";
	cin.getline(address,100);
	cout << "Re-enter Telephone Number: ";
	cin >> *telno;
}

void derived::disp()
{
	cout << setw(15) << name << setw(11) << *dob << setw(11) << bg << setw(8) << *height << setw(9) << *weight << setw(17) << policyno << setw(14) << address << setw(22) << *telno << setw(17) << driverno << endl;
}
int main()
{
	int resp,i,n = 0,c = 0;
	char temp[15];
	derived *b[50],*tempobj;
	do
	{
		cout << "\n1. Build a Master Table\n2. Display Records\n3. Insert A Record\n4. Delete A Record\n5. Edit A Record\n6. Search A Record\n7. Exit\nYour Choice? ";
		cin >> resp;
		switch(resp)
		{
			case 1: cout <<"How many records do you wish to create? ";
				  cin >> n;
				  for(i = 0;i < n;i++)
				  {
				  	b[i] = new derived;
				  	b[i] -> add();  					  				  	
				  }
				  break;
			case 2: cout << "\nMaster Table\n" << endl << setw(10) << "Name" << setw(20) << "Date of Birth" << setw(8) << "BG" << setw(10) << "Height" << setw(10) << "Weight"<< setw(15) << "Policy No." << setw(15) << "Locality" << setw(22) << "Telephone No." << setw(15) << "DL No." << endl;
				  for(i = 0;i < n;i++)
				  {  
			 		b[i] -> disp();
			 	  }
				  break;
			case 3: n += 1;
			        b[n-1] = new derived;
				  b[n-1] -> add();
				  break;
			case 4: cout << "Enter DL No. to be deleted: ";
				  cin >> temp;
				  for(i = 0;i < n;i++)
				  {
				  	c = 0;
				  	b[i] -> search(temp,&c);
					if(c == 1)
						break;
				  }
				  if(c == 1)
				  {
				  	  tempobj = new derived;
				  	  tempobj = b[n-1];
				  	  delete(b[i]);
				  	  b[i] = tempobj;
				  	  derived::delrec();
				  	  n -= 1;
				  	  cout << "Record Deleted!" << endl;
				  }
				  else 
					  cout << "Record Unavailable. Inconvenience is Regretted." << endl;
				  break;
			case 5: cout << "Enter DL No. to be edited: ";
				  cin >> temp;
				  for(i = 0;i < n;i++)
				  {
				  	c = 0;
				  	b[i] -> search(temp,&c);
					if(c == 1)
						break;
				  }
				  if(c == 1)
				  	  b[i] -> update();
				  else 
					  cout << "Record Unavailable. Inconvenience is Regretted." << endl;
				  break;
			case 6: cout << "Enter DL No. to be searched: ";
				  cin >> temp;
				  for(i = 0;i < n;i++)
				  {
				  	c = 0;
				  	b[i] -> search(temp,&c);
					if(c == 1)
						break;
				  }
				  if(c == 1)
				        cout << "Record Found!" << endl;
				  else 
					  cout << "Record Unavailable. Inconvenience is Regretted." << endl;
				  break;
			case 7: return 1;
		}
	}while(resp != 7);
	return 0;
}
