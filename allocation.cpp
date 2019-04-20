#include <iostream>
using namespace std;
void first(int hard[], int size, int p[], int psize)
{
    cout << "In First Fit\n";
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = hard[i];
    for (int i = 0; i < psize; i++)
    {
        int flag = 0, m = 0;
        while (flag == 0 && m < size)
        {
            if (p[i] < hard[m])
            {
                hard[m] = hard[m] - p[i];
                cout << "Process " << i + 1 << " is allocated in " << arr[m] << " size block \n";
                flag = 1;
            }
            m++;
        }
    }
    cout << endl;
}
void best(int hard[], int size, int p[], int psize)
{
    cout << "In best fit\n";
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = hard[i];
    for (int i = 0; i < psize; i++)
    {
        int diff = 10000, m = 0, flag = 0;
        for (int j = 0; j < size; j++)
        {
            int temp = hard[j] - p[i];
            if (temp < diff && temp >= 0)
            {
                diff = temp;
                m = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            hard[m] -= p[i];
            cout << "Process " << i + 1 << " is allocated in " << arr[m] << " size block \n";
        }
    }
    cout << endl;
}
void worst(int hard[], int size, int p[], int psize)
{
    cout << "In worst fit\n";
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = hard[i];
    for (int i = 0; i < psize; i++)
    {
        int diff = 0, m = 0, flag = 0;
        for (int j = 0; j < size; j++)
        {
            int temp = hard[j] - p[i];
            if (temp > diff && temp >= 0)
            {
                diff = temp;
                m = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            hard[m] -= p[i];
            cout << "Process " << i + 1 << " is allocated in " << arr[m] << " size block \n";
        }
    }
    cout << endl;
}
int main()
{
    int hard[] = {100, 200, 300, 250};
    int proc[] = {50, 150, 310, 10};
    first(hard, 4, proc, 4);
    best(hard, 4, proc, 4);
    worst(hard, 4, proc, 4);
    return 0;
}