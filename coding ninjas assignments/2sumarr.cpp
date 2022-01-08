#include<iostream>
using namespace std;
void pairsum(int arr[], int n,int key)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == key)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    int a[9] = { 1, 3, 6 ,2 ,5, 4, 3, 2 ,4 };
    pairsum(a,9,7);
}