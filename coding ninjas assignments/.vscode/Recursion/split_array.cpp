#include<iostream>
using namespace std;
void partition(int a[], int n, int s , int e)
{
    // int m = (s+e)/2;
    int part;
   
   for(int i = 0; i < n ; i++)
   {
       for(int j = 0;j < n ; j++)
       {
           if(a[i] == a[i] + a[j] && a[i] != a[j])
           {
               part = a[i];

           }
       }
   }
}
bool splitArray(int a[], int n)
{
    
}