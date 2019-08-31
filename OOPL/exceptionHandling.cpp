#include<iostream>
using namespace std;

class ExceptionHandling
{	
	double n,d,result;
	public:
		void input();
		void divide();
		void display();
};

void ExceptionHandling::input()
{
	cout << "Numerator: ";
	cin >> n;
	cout << "Denominator: ";
	cin >> d;
}

const int DivideByZero = 10;

void ExceptionHandling::divide()
{
	if(d == 0)
		throw DivideByZero;
	else
		result = (n/d);
}

void ExceptionHandling::display()
{
	cout << "Result = " << n << "/" << d << " = " << result << endl;
}		

int main()
{
	int resp;
	double res;
	ExceptionHandling a;
	do
	{
		cout <<"\n1. Input Numbers\n2. Display Result\n3. Exit\nYour Choice? ";
		cin >> resp;
		switch(resp)
		{
			case 1: a.input();
				break;
			case 2: try
				{
					a.divide();
					a.display();
				}					
				catch(int i)
				{
					if(i == DivideByZero)
						cout << "Cannot divide by zero." << endl;
				}
				break;
			case 3: return 1;
		}
	}while(resp != 3);
	return 0;
}
