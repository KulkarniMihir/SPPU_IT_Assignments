#include<iostream>
#include<iomanip>
using namespace std;

class personal
{
    protected:
        char *name = NULL,*bg = NULL,*dob = NULL;
    public:
        personal()
        {
            name = new char[50];
            bg = new char[5];
            dob = new char[25];
        }
};

class professional
{
    protected:
        int *n_years;
        char *skill_expert;
    public:
        professional()
        {
            n_years = new int;
            skill_expert = new char[20];
        }
};

class academic
{
    protected:
        float *deg_per;
    public:
        academic()
        {
            deg_per = new float;
        }
};

class employee:public personal,public professional,public academic
{
    public:
        void input();
        void display();
};

void employee::input()
{
    cin.ignore();
    cout << "\nPersonal Details:\n";
    cout << "Enter Name of Employee: ";
    cin.getline(name,50);
    cout << "Blood Group: ";
    cin.getline(bg,5);
    cout << "Date of Birth: ";
    cin.getline(dob,25);
    cout << "\nProfessional Details:\n";
    cout << "Years of Experience: ";
    cin >> *n_years;
    cin.ignore();
    cout << "Skill Expertise: ";
    cin.getline(skill_expert,20);
    cout << "\nAcademic Details:\n";
    cout << "Degree Percentile: ";
    cin >> *deg_per;
}

void employee::display()
{
    cout << setw(5) << name << setw(2) << bg << setw(5) << dob << setw(5) << *n_years << setw(5) << skill_expert << setw(5) << *deg_per;
}

int main()
{
    int resp,i,n;
    employee *b[15];
    do
    {
            cout << "\n1. Read Details\n2. Display Details\n3. Exit\nYour Choice? ";
            cin >> resp;
            switch(resp)
            {
                case 1: cout << "Number of Records: ";
                        cin >> n;
                        for(i = 0;i < n;i++)
                        {
                            cout << "Employee #" << i+1;
                            b[i] = new employee;
                            b[i] -> input();
                        }
                        break;
                case 2: cout << setw(10) << "Name" << setw(10) << "BG" << setw(13) << "DoB" << setw(15) << "WorkEx" << setw(10) << "Skill" << setw(20) << "Deg. Percentile\n";
                        for(i = 0;i < n;i++)
                        {
                            b[i] -> display();
                        }
                        break;
                case 3: return 0;
                default: cout << "\nPlease enter a valid response.\n";
                         break;
            }
    }while(resp != 3);
    return 0;
}
