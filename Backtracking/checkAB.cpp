#include<iostream>
#include<string>
using namespace std;
#include <iostream>
using namespace std;
int length(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char a[10] = "ABCD";
    int l = length(a);
    cout << l << endl;
}
// bool checkHelper(char a[], int index)
// {
//     int n = length(a);
//     if(n == 0)
//     {
//         return false;
//     }
    
//     if(a[index] == 'a' ){
//         if(a[index+1] == ' ' || a[index] == 'a' || (a[index+1] == 'b' && a[index+2] == 'b'))
//         {
//             if(a[index+1] == 'b' && a[index+2] == 'b')
//             {
//                 if(a[index+3] == ' ' || a[index+3] == 'a')
//                 {
//                     return true;
//                 }
//                 return false;
//             }
//             else{
//                 return true;
//             }
//         }

//     }
//     else{
//         return false;
//     }
//     return checkHelper(a,index+1);
// }
bool checkHelper(char a[], int index)
{
    int n = length(a);
    if (n == 0)
    {
        return false;
    }
    // if(index == n)
    // {
    //     return false;
    // }
    bool b = checkHelper(a,index+1);
    if (a[index] == 'a')
    {
        if (a[index + 1] == ' ' || a[index] == 'a' || (a[index + 1] == 'b' && a[index + 2] == 'b'))
        {
            if (a[index + 1] == 'b' && a[index + 2] == 'b')
            {
                if (a[index + 3] == ' ' || a[index+3] == '\0' a[index + 3] == 'a')
                {
                    b = true;
                }
                b =  false;
            }
            else
            {
                b = true;
            }
        }
    }
    else
    {
        b = false;
    }
    return b;
}