#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
const int n = 10000;
using namespace std;
void selection(int *ar, int size)
{
    clock_t start = clock();
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
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Sorting method selection:" << endl;
    printf("The time of the procedure: %f seconds\n", seconds);
}
void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
    clock_t start = clock();
    int i, k, n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i] = 0;
    for (i = 0; i < n; i++)
        cr[ar[i]] += 1;
    for (i = 1; i < k + 1; i++)
        cr[i] += cr[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        br[cr[ar[i]] - 1] = ar[i];
        cr[ar[i]] -= 1;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Sorting method radix" << endl;
    printf("The time of the procedure: %f seconds\n", seconds);
}
int main()
{
    int sizeC = 10;
    int  i, a[n], b[n], c[10],d[n];
    for (i = 0; i < n; i++)
    {
        a[i] = 0 + rand() % 9;
        d[i] = a[i];
    }
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
    for (i = n-10; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    radix(d, b, c, sizeC, n);
    cout << "Sorted array\n";
    cout << "First 10 elements of the sorted array: ";
    for (i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;
    cout << "The last 10 elements of the sorted array: ";
    for (i = n-10; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}
