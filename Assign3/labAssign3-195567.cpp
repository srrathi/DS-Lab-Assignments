#include <bits/stdc++.h>
using namespace std;

class assign3
{
    int n;
    int *p;
    int num;
    int pos;
    bool find = false;

public:
    // constructor function to take values
    assign3()
    {
        cout << "Enter the size of array to input :" << endl;
        cin >> n;
        p = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the " << i + 1 << " element of Array :" << endl;
            cin >> *(p + i);
        }
        sort(p, p + n);
        cout << "Enter the number which you want to search or insert in array :" << endl;
        cin >> num;
    }

    // Binary Search Function
    void binarySearch()
    {
        int start = 0, end = n;
        while (start < end)
        {
            int k = (start + end) / 2;
            if (p[k] == num)
            {
                cout << "Congrats number found!!" << endl;
                // cout << "Index value in sorted array is " << k << endl;
                pos = k;
                find = true;
                deleteNum();
                break;
            }
            else if (p[k] > num)
            {
                end--;
            }
            else if (p[k] < num)
            {
                start++;
            }
        }

        if (find == false)
        {
            addNum();
        }
    }

    // To remove the number from array
    void deleteNum()
    {
        for (int i = pos; i < n - 1; i++)
        {
            p[i] = p[i + 1];
        }
        cout << "The new array after removing that number is :" << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << p[i] << endl;
        }
    }

    // To add number at new position
    void addNum()
    {
        cout << "Enter the position in sorted array where you want to insert new no. :" << endl;
        cin >> pos;
        for (int i = n; i >= pos; i--)
        {
            p[i] = p[i - 1];
        }

        p[pos - 1] = num;

        cout << "Array after adding new Number is :" << endl;
        for (int i = 0; i <= n; i++)
        {
            cout << p[i] << endl;
        }
    }

    // Destructor function to delete dynamically made array
    ~assign3()
    {
        delete[] p;
    }
};

int main()
{
    assign3 obj;
    obj.binarySearch();
    return 0;
}