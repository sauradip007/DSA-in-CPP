#include <iostream>
using namespace std;
void sortArray(int a[], int n)
{
 

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
void printunique(int a[], int n)
{
    sortArray(a,n);
    int i = 0;
    while(i < n)
    {
        if(a[i] != a[i+1])
        {
            cout<<a[i];
            break;
        }
        i++;
    }

}
int main()
{

    int a[7] = {2, 3, 1, 6, 3, 6, 2};
    printunique(a, 7);
 ;
}
