

#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
// DP
int editDistance_DP(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **output = new int* [m+1];
    for(int i = 0 ; i <= m; i++)
    {
        output[i] = new int [n+1];
    }
    //We know 0,0 will occupy 0
    output[0][0] = 0;
    //filling first row and first column
    for(int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }
    for(int j = 1; j <= n; j++)
    {
        output[0][j] = j;
    }
    //
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(s1[m-i] == s2[n-j])
            {
                output[i][j] = output[i-1][j-1];

            }
            else{
                int a = output[i-1][j-1];
                int b = output[i-1][j];
                int c = output[i][j-1];
                output[i][j] = min(a,min(b,c))+1;
            }
        }
    }
    return output[m][n];
}
// int editDistance_mem(string s1, string s2, int **output)
// {
//     int m = s1.length();
//     int n = s2.length();
//     int ans;
//     if(m == 0 || n == 0)
//     {
//         return max(m,n);
//     }
//     if(output[m][n] != -1)
//     {
//         return output[m][n];
//     }
//     else{
//             int a = editDistance_mem(s1.substr(1), s2,output)+1; //insert
//             int b = editDistance_mem(s1, s2.substr(1),output)+1; //delete
//             int c = editDistance_mem(s1.substr(1), s2.substr(1),output)+1;//updation
//             ans =  min(a,min(b,c));

//     }
//     //Save ans
//      output[m][n] = ans;
//     return output[m][n];
// }
// int editDistance(string s1, string s2)
// {
//     int m = s1.length();
//     int n = s2.length();
//     int **output = new int*[m+1];
    
//     for(int i = 0 ; i <= m; i++)
//     {
//         output[i] = new int[n+1];
//         for(int j = 0; j <= n ; j++)
//         {
//             output[i][j] = -1;
//         }
//     }
//     return editDistance_mem(s1,s2,output);
// }
int main()
{
    string s = "horse";
    string t = "ros";
    cout<<editDistance_DP(s,t)<<endl;
}