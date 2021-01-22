#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    float cgpi;
    int sem;
};

int main()
{
    Student stud[6];
    string l;
    // Entering Data inta Student class object
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Name, Roll no., CGPI and sem of Student " << i + 1 << ":" << endl;
        // cin.ignore();
        // getline(cin, stud[i].name, '\n');
        // cin >> stud[i].roll;
        // cin >> stud[i].cgpi;
        // cin >> stud[i].sem;
        getline(cin, stud[i].name, '\n');
        getline(cin, l);
        stringstream rollstream(l);
        rollstream >> stud[i].roll;
        getline(cin, l);
        stringstream cgpistream(l);
        cgpistream >> stud[i].cgpi;
        getline(cin, l);
        stringstream semstream(l);
        semstream >> stud[i].sem;
        if (i == 4)
        {
            cout << "You have Entered all the Enteries" << endl;
        }
    }

    //Taking threshold CGPI
    float k;
    cout << "Enter the threshold CGPI" << endl;
    cin >> k;

    cout << "These are the Students with CGPI greater than Threshold CGPI:" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (stud[i].cgpi > k)
        {
            cout << "Name - " << stud[i].name << endl;
            cout << "Roll no. - " << stud[i].roll << endl;
            cout << "CGPI - " << stud[i].cgpi << endl;
            cout << "Semester - " << stud[i].sem << endl
                 << endl;
        }
    }

    //Entering data at a desired Position and storing it
    Student S[6];
    int pos;
    cout << "Enter the position at which you want to enter the data :" << endl;
    cin >> pos;
    if (pos > 0 && pos < 6)
    {
        cout << "The value of Position is valid Processing..." << endl;
    }
    else
    {
        cout << "Invalid Position value" << endl;
    }

    for (int i = 0, j = 0; i < 5, j < 6; i++, j++)
    {
        if (j == pos - 1)
        {
            cout << "Enter the data for New Position " << pos << endl;
            cin.ignore();
            getline(cin, S[j].name, '\n');
            cin >> S[j].roll;
            cin >> S[j].cgpi;
            cin >> S[j].sem;
            i--;
        }
        else
        {
            S[j] = stud[i];
        }
    }

    for (int i = 0; i < 6; i++)
    {
        stud[i] = S[i];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "Name - " << stud[i].name << endl;
        cout << "Roll no. - " << stud[i].roll << endl;
        cout << "CGPI - " << stud[i].cgpi << endl;
        cout << "Semester - " << stud[i].sem << endl
             << endl;
    }

    return 0;
}