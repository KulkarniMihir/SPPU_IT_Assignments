/*
Roll Number: 23150
Batch: H9
Problem Definition: Create a class named weather report that holds a daily weather report with data members day_of_month, hightemp, lowtemp,amount_rain and amount_snow. Use different types of constructors to initialize the objects. Also include a function that prompts the user and sets values for each field so that you can override the default values. Write a menu driven program in C++ with options to enter data and generate monthly report that displays average of each attribute.
Date of Performance: 20/06/2019
*/


#include<iostream>
#include<iomanip>

using namespace std;

class weather_report
{	
	private:
		int day;
		float highT,lowT,rain,snow;
		static float avglt,avght,avgs,avgr;
	public:
		weather_report()
		{
			day = 1;
			highT = 0;
			lowT = 0;
			rain = 0;
			snow = 0;
		}
		void inp()
		{
			cout << "High Temperature: ";
		   	while(1)
		   	{
				cin >> highT;
				if((highT > 50) || (highT < 10))
				{	
					cout << endl << "Please enter a valid attribute: "; 		
				}
				else break;
		   	}
			cout << "Low Temperature: ";
			while(1)
			{
				cin >> lowT;
				if((lowT > highT) || (lowT < 0))
				{
					cout << endl << "Please enter a valid attribute: ";	
				}
				else break;
			}
			cout << "Amount of Rainfall: ";
			while(1)
			{
				cin >> rain;
				if((rain > 25) || (rain < 5))
				{
					cout << endl << "Please enter a valid attribute: ";
				}
				else break;
			}
			cout << "Amount of Snow: ";
			while(1)
			{
				cin >> snow;		
				if((snow < 5) || (snow > 25)) 
				{
					cout << endl << "Please enter a valid attribute: ";
				}
				else break;
			}
		}
		void disp(int d)
		{
			cout << setw(5) << d << setw(12) << highT << setw(20) << lowT << setw(23) << rain << setw(22) << snow << endl;
		}
		static void avg(weather_report a[],int m)
		{
			int i;
			for(i = 0;i < 30;i++)
			{
				avght += a[i].highT;
				avglt += a[i].lowT;
				avgr += a[i].rain;
				avgs += a[i].snow;
			}
			if(m == 0){ m = 1;}
			cout << "AVERAGE WEATHER REPORT" << endl;
			cout << "High Temperature" << setw(4) << ":" << setw(3) << (avght/m) << endl;
			cout << "Low Temperature" << setw(5) << ":" << setw(3) << (avglt/m) << endl;
			cout << "Amount of Rainfall" << setw(2) << ":" << setw(3) << (avgr/m) << endl;
			cout << "Amount of Snow" << setw(6) << ":" << setw(3) << (avgs/m) << endl;
		}
};
float weather_report :: avght = 0;
float weather_report :: avglt = 0;
float weather_report :: avgr = 0;
float weather_report :: avgs = 0;			
int main()
{
	int i,j,n,d;
	weather_report a[30];	
	do
	{
		cout << "1. Enter Weather Details" << endl << "2. Display Details" << endl << "3. Average Weather Report" << endl << "4. Exit" << endl;
		cin >> i;
		switch(i)	
		{
			case 1: cout <<"Enter number of days: ";
				while(1)
				{
					cin >> n;
					if(n > 30)
						cout << "Please enter a valid attribute: ";
					else break;
				}
				for(j = 0;j < n;j++)
				{
					cout << "Which day's details do you wish to enter? ";
					while(1)
					{
						cin >> d;
						if(d > 30)
							cout << "Please enter a valid attribute: ";
						else break;
					}
					cout << "Day " << d << endl;
					a[d-1].inp();
				}
				break;
			case 2: cout << setw(5) << "Day" << setw(20) << "High Temperature" << setw(20) << "Low Temperature" << setw(25) << "Amount of Rainfall" << 						setw(20) << "Amount of Snow" << endl;
				for(j = 0;j < 30;j++)
				{
					a[j].disp(j+1);
				}
				break;
			case 3: weather_report :: avg(a,n);
				break;
			case 4: return 0;
		}
	}while(i != 4);
	return 0;
}
