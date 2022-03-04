#include<iostream>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
//DP
int lcs_DP(string s, string t)
{
    int m = s.length();
    int n  = t.length();
    int ** output = new int*[m+1];
    for(int i = 0; i <= m ; i++)
    {
        output[i] = new int [n+1];
    }
    //array allocated

    //We will fill first row with 0 and first column with 0 as decided as lcs of anything with an empty string yields 0
    for(int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }
    for(int i = 0 ; i <= m ; i++)
    {
        output[i][0] = 0;
    }


    for(int i = 1; i <= m ; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // To check if first char matches
            if(s[m-i] == t[n-j])
            {
                output[i][j] = 1 + output[i-1][j-1]; //denoting s.substr(1) and t.substr(1) in this case
            }
            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = max(a,max(b,c));
            }

        }
    }
    return output[m][n];
}
//memoization
int LCS_mem(string s, string t, int **ans)
{
    int m = s.length();
    int n = t.length();
    //Base case
    if(s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    
    //Check if ans exists
    if(ans[m][n] != -1)
    {
        return ans[m][n];
    }
    // Recursive calls
    int x = INT_MIN;
    int y = INT_MIN;
    int a = INT_MIN;
            //call for rest of the string to check
            if(s[0] == t[0])
            {

                int z = LCS_mem(s.substr(1), t.substr(1),ans);
              return 1+z;
            }
            else{
                x = LCS_mem(s, t.substr(1),ans);
                y = LCS_mem(s.substr(1), t,ans);
                a = LCS_mem(s.substr(1), t.substr(1),ans); //redundant
                // return max(x,max(y,a));

                 ans[m][n] = max(x, y);
            }
            // ans[m][n] = answer;
            return ans[m][n];
}
int LCS(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int ** ans = new int* [m+1]; //answer array will have m+1 * n+1 rows and columns as discussed from the unique calls logic
    for(int j = 0 ; j <=m ; j++)
    {
        ans[j] = new int [n+1];
    }
    for(int i = 0; i <= m ; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
            //initialising 2d array with -1
        }
    }
    return LCS_mem(s,t,ans);
}
// int LCS(string s, string t)
// {
//     if(s.length() == 0 || t.length() == 0)
//     {
//         return 0;
//     }

//     // if(s.length() == 1 && t.length() == 1)
//     // {
//     // if(s[0] == t[0])
//     // {
//     //     return 1;
//     // }
//     // return 0;
//     // }
// int x = INT_MIN;
// int y = INT_MIN;
// int a = INT_MIN;
//         //call for rest of the string to check
//         if(s[0] == t[0])
//         {
          
//             int z = LCS(s.substr(1), t.substr(1));
//           return 1+z;
//         }
//         else{
//             x = LCS(s, t.substr(1));
//             y = LCS(s.substr(1), t);
//             a = LCS(s.substr(1), t.substr(1)); //redundant
//             // return max(x,max(y,a));

//             return max(x, y);
//         }
         
        
    
    
// }
int main()
{
    string s = "xyz";
    string t = "zxay";
    cout<<lcs_DP(s,t)<<endl;
}