#include <iostream>
using namespace std;
// int subsetSumToK(int input[], int n, int output[][50], int k)
// {
//     if (input == 0)
//     {
//         output[0][0] = 0;
//         return 0;
//     }
//     int smallOutput1 = subsetSumToK(input + 1, n - 1, output, k - input[0]);
//     int smallOutput2 = subsetSumToK(input + 1, n - 1, output, k);
// }
void printsumk(int a[], int k, int output[], int i, int n, int m = 0)

{
    // if (i == n)
    // {
    //     if (k == 0)
    //     {
    //         for (int l = 0; l < m; l++)
    //         {
    //             cout << output[l] << " ";
    //         }
    //         cout << endl;
    //         return;
    //     }
    //     else
    //     {
    //         return;
    //     }
    // }
    
    // int newOutput[1000];
    // printsumk(a, k, output, i + 1, n - 1, m); // not taking a[0]

    // for (int j = 0; j < m; j++)
    // {
    //     newOutput[j] = output[j];
    // }
    // newOutput[m] = a[i];
    // printsumk(a, k - a[i], newOutput, i + 1, n, m+1); // taking a[0]
    //---------------------------------------------------------------
    if (k == 0)
    {
        for (int l = 0; l < m; l++)
        {
            cout << output[l] << " ";
        }
        cout << endl;
        return;
    }

    if (n == 0)
    {
        return;
    }

    int newOutput[1000];
    printsumk(a, k, output, i + 1, n - 1, m); // not taking a[0]

    for (int j = 0; j < m; j++)
    {
        newOutput[j] = output[j];
    }
    newOutput[m] = a[i];
    printsumk(a, k - a[i], newOutput, i + 1, n - 1, m + 1); // taking a[0]
}
int main()
{
    int a[9] = {5 ,12 ,3 ,17 ,1, 18, 15 ,3 ,17};
    int output[1000];
    int i = 0;
//     9 
// 5 12 3 17 1 18 15 3 17 
// 6

    int m;
    printsumk(a, 6, output, i, 9, m);
}