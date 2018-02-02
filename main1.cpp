#include<iostream>
const int n = 10000;
using namespace std;
void selection(int *ar, int size)
{
    int i, j, mx, nmx;

    for (i = 0; i < size - 1; i++)
    {
        mx = ar[i];
        nmx = i;
        for (j = i + 1; j < size; j++)
        {
            if (ar[j]<mx)
            {
                mx = ar[j];
                nmx = j;
            }
        }
        ar[nmx] = ar[i];
        ar[i] = mx;
    }
}
int main()
{
    int  i, a[n];
    for (i = 0; i < n; i++)
        a[i] = rand();
   cout << "The first 10 elements of the array: ";
    for (i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    selection(a, n);
    cout << "Sorted array\n";
        cout << "First 10 elements of the sorted array: ";
    for (i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "The last 10 elements of the sorted array: ";
    for (i =n-10; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}

