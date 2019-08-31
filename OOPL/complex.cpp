#include<iostream>
using namespace std;

class complex
{
	float re,im;
	public: complex()
		{
			re = 0;
			im = 0;
		}
		complex(float a, float b)
		{
			re = a;
			im = b;
		}
		//  << >> ++ pre, post  
	friend istream& operator >>(istream&, complex&);
	friend ostream& operator <<(ostream&,const complex&);
	friend complex operator +(complex, complex);
	friend complex operator -(complex, complex);
	void display();
	complex operator *(complex);
	complex operator /(complex);
};

istream& operator >>(istream& in, complex &obj)
{
	cout << "Re(Z): ";
	cin >> obj.re;
	cout << "Im(Z): ";
	cin >> obj.im;
	return in;
}

ostream& operator <<(ostream& out,const complex& obj)
{
	if(obj.im < 0)
	{
		out << obj.re << " - " << (-1)*obj.im << "i" << endl;
	}
	else
	{
		out << obj.re << " + " << obj.im << "i" << endl;
	}
	return out;
}

complex operator +(complex z1,complex z2)
{
	complex temp;
	temp.re = z1.re + z2.re;
	temp.im = z1.im + z2.im;
	return temp; 
}

complex operator -(complex z1,complex z2)
{
	complex temp;
	temp.re = z1.re - z2.re;
	temp.im = z1.im - z2.im;
	return temp; 
}

complex complex :: operator *(complex z)
{
	complex temp;
	temp.re = ((this -> re)*(z.re) - (this -> im)*(z.im));
	temp.im = ((this -> re)*(z.im) + (this -> im)*(z.re));
	return temp;
}

complex complex :: operator /(complex z)
{
	complex temp,temp1,temp2;
	temp1.re = z.re;
	temp1.im = (-1) * z.im;
	temp2 = z * temp1;
	temp.re = (this -> re);
	temp.im = (this -> im);
	temp = temp * temp1;
	temp.re /= (temp2.re);
	temp.im /= (temp2.re);
	return temp;
}

void complex::display()
{
	if(im < 0)
	{
		cout << re << " - " << (-1)*im << "i" << endl;
	}
	else if(im >= 0)
		cout << re << " + " << im << "i" << endl;
}

int main()
{
	int i,resp;
	complex result,z1,z2;
	float re1,re2,im1,im2;
	do
	{
		cout << "\n\nCOMPLEX NUMBERS\n\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\nYour Choice? ";
		cin >> resp;
		cout << endl;
		switch(resp)
		{
			case 1: {
					cout << "Z1: \n";
					cin >> z1;
					cout << "Z2: \n";
					cin >> z2;
					cout << endl;
					cout << "Z1 = " << z1;
					cout << "Z2 = " << z2;
					result = z1 + z2;
					cout << "\nZ1 + Z2 = ";
					result.display();
					break;
				}
			case 2: {
					cout << "Z1: \n";
					cin >> z1;
					cout << "Z2: \n";
					cin >> z2;
					cout << endl;
					cout << "Z1 = " << z1;
					cout << "Z2 = " << z2;
					result = z1 - z2;
					cout << "\nZ1 - Z2 = ";
					result.display();
					break;
				}
			case 3: {
					cout << "Z1: \n";
					cin >> z1;
					cout << "Z2: \n";
					cin >> z2;
					cout << endl;
					cout << "Z1 = " << z1;
					cout << "Z2 = " << z2;
					result = z1 * z2;
					cout << "\nZ1 * Z2 = ";
					result.display();
					break;
				}
			case 4: {
					cout << "Z1: \n";
					cin >> z1;
					cout << "Z2: \n";
					cin >> z2;
					cout << endl;
					cout << "Z1 = " << z1;
					cout << "Z2 = " << z2;
					result = z1 / z2;
					cout << "\nZ1 / Z2 = ";
					result.display();
					break;
				}
			case 5: return 1;
				break;
			default: cout << "Please enter a valid response." << endl;
				 break;
		}
	}while(resp != 5);
	return 0;
}

