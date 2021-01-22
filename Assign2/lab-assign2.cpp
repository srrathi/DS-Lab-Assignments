#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    float cgpi;
    int sem;
};

const int LINE = 5;

int main()
{
    Student stud[5];
    // Entering Data inta Student class object
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Name, Roll no., CGPI and sem of Student " << i + 1 << ":" << endl;
        cin.ignore();
        getline(cin, stud[i].name, '\n');
        cin >> stud[i].roll;
        cin >> stud[i].cgpi;
        cin >> stud[i].sem;
        if (i == 4)
        {
            cout << "You have Entered all the Enteries" << endl << endl;
        }
    }

    // Entering Data into the text file
    ofstream myfile("example.txt", std::ios_base::app);
    for (int i = 0; i < 5; i++)
    {
        if (myfile.is_open())
        {
            myfile << stud[i].name << ", " << stud[i].roll << ", " << stud[i].cgpi << ", " << stud[i].sem << endl;
        }
        else
            cout << "Unable to open file" << endl;
    }
    myfile.close();

    //Taking threshold CGPI
    float k;
    cout << endl << "Enter the threshold CGPI" << endl;
    cin >> k;

    // Opening file to read data
    ifstream f("example.txt");
    string s;

    cout << endl << "These are the Students with CGPI greater than Threshold CGPI:" << endl;
    for (int i = 1; i <= LINE; i++)
    {
        if (stud[i - 1].cgpi > k)
        {
            getline(f, s);
            cout << s << endl;
        }
        else
        {
            getline(f, s);
        }
    }

    //Entering data at a desired Position and storing it
    Student S[6];
    int pos;
    cout << endl << "Enter the position at which you want to enter the data :" << endl;
    cin >> pos;
    if (pos > 0 && pos < 6)
    {
        cout << "The value of Position is valid Processing..." << endl << endl;
    }
    else
    {
        cout << "Invalid Position value" << endl;
    }

    for (int i = 0, j = 0; i < 5, j < 6; i++, j++)
    {
        if (j == pos - 1)
        {
            cout << "Enter the Name, Roll no, CGPI and Semester for New Position " << pos << endl;
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

    // Updating the text file with updated data
    ofstream ofs;
    ofs.open("example.txt", ios::out | ios::trunc);
    for (int i = 0; i < 6; i++)
    {
        if (ofs.is_open())
        {
            ofs << S[i].name << ", " << S[i].roll << ", " << S[i].cgpi << ", " << S[i].sem << endl;
        }
        else
            cout << "Unable to open file" << endl;
    }
    cout << endl << "Your Data has been Updated in file" << endl;
    ofs.close();
    return 0;
}
