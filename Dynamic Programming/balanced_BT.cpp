#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
// int balancedBT(int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }
//     if(n == 1)
//     {
//         return 1;
//     }
//     if(n == 2)
//     {
//         return 3;
//     }
//     //we have to check for the (n-1)th level
    
//     //max total children nth level will have is 2^n-1 , children of parent which is at the n-1th level , for 1 its 2^1 for 2 its 2^2
//     // int maxChildren = 0;
//     int maxChildren = pow(2,n-1);
//     //total no. of possible combinations would be 2^maxchildren - 1 when prev level is completely filled
//     int rootTotal = 0;
//      rootTotal = rootTotal + pow(2,maxChildren) -1;

//     //possible combinations of right and left subtree are (h-1) (h-1) , (h-1) (h-2) , (h-2) (h-1)
//     int x = balancedBT(n-1);
//     int y = balancedBT(n-1);

//     int a = balancedBT(n-2);
//     int b = balancedBT(n-1);

//     int c = balancedBT(n-1);
//     int d = balancedBT(n-2);

//     return x+y+a+b+c+d;
// }

// int balancedBTs(int n)
// {
//     // Write your code here
//     int totalCount = 0;
//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (n == 2)
//     {
//         return 3;
//     }
//     // we have to check for the (n-1)th level

//     // max total children nth level will have is 2^n , for 1 its 2^1 for 2 its 2^2
//     //  int maxChildren = 0;
//     //the children in the prev level can vary from 1 to n
//     // int maxChildren = pow(2, n - 1);
//     // total no. of possible combinations would be 2^maxchildren - 1 when prev level is completely filled

//     // totalCount += pow(2, maxChildren) - 1;
//     int maxChildren;
//     for(int i = 1; i <= 2 ; i++)
//     {
//         maxChildren = pow(2,i);
//         //the possibilities corresponding level will be
//         totalCount += pow(2,maxChildren)-1; // can or cannot consider it
//     }
//     // possible combinations of right and left subtree are (h-1) (h-1) , (h-1) (h-2) , (h-2) (h-1)
//     totalCount += balancedBTs(n - 1);
//     totalCount += balancedBTs(n - 1);

//     totalCount += balancedBTs(n - 2);
//     totalCount += balancedBTs(n - 1);

//     totalCount += balancedBTs(n - 1);
//     totalCount += balancedBTs(n - 2);

//     return totalCount;
// }
int balancedBT(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 3;
    }
    //To handle extremely large values
    int mod = (int)(pow(10,9))+7;
    int x = balancedBT(n-1);
    int y = balancedBT(n-2);
    int temp1 = (int)((long)(x*x)) % mod;
    int temp2 = (int)(2*(long)(x*y)) % mod;
    int ans = (temp1 + temp2) % mod;
    // int ans = x*x + 2*x*y;
    return ans;

}
int main()
{
    int h;
    cout<<"Enter height : "<<endl;
    cin>>h;
    cout<<balancedBT(h)<<endl;

}