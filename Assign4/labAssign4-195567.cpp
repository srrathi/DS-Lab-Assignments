#include <iostream>
using namespace std;
int main()
{
    int *a, flag, i;
    int n;
    cout << "Enter the no. of elements you want to put in array :" << endl;
    cin >> n;
    a = new int[n];
    for (int k = 0; k < n; k++)
    {
        cout << "Enter the " << k + 1 << " element of array :" << endl;
        cin >> a[k];
    }

    //Bubble Sort Algorithm
    int end = n - 1;
    for (i = 1; i <= n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j <= end - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    cout << "The no. of Iterations the loop runned is " << i << endl;
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << ", ";
    }
    cout<<endl;
    delete[] a;
    return 0;
}