#include<iostream>
using namespace std;

class shape
{
    public:
        virtual double compute_area()=0;
};

class triangle:public shape
{
    int h,b;
    public:
        void input();
        double compute_area()
        {
            return(0.5*b*h);
        }
};

void triangle::input()
{
    cout << "Height: ";
    cin >> h;
    cout << "Base: ";
    cin >> b;
}

class rectangle:public shape
{
    int l,b;
    public:
        void input();
        double compute_area()
        {
            return(b*l);
        }
};

void rectangle::input()
{
    cout << "Length: ";
    cin >> l;
    cout << "Breadth: ";
    cin >> b;
}

int main()
{
    int resp;
    triangle *t;
    rectangle *r;
    double l,b;
    do
    {
        cout << "\n1. Calculate Area of Triangle\n2. Calculate Area of Rectangle\n3. Exit\nYour Choice? ";
        cin >> resp;
        switch(resp)
        {
            case 1: t = new triangle;
                    t -> input();
                    cout << "Area of given triangle is: " << t -> compute_area() << " sq. units" << endl;
                    delete(t);
                    break;
            case 2: r = new rectangle;
                    r -> input();
                    cout << "Area of given rectangle is: " << r -> compute_area() << " sq. units" << endl;
                    delete(r);
                    break;
            case 3: break;
            default: cout << "\nPlease enter a valid response.\n";
                     break;
        }
    }while(resp != 3);
    return 0;
}
