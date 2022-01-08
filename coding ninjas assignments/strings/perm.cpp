#include<iostream>
using namespace std;
int len (char a[])
{
    int count = 0;
     for(int i = 0 ;  a[i] != '\0' ; i++)
    {
        count++;
    }
    return count;

}

int main()
{
    char a[4] = "abc";
    char b[4] = "cbd";
    int arr1[26];
    int arr2[26];
    bool isPerm =  false;
    for(int i = 0 ; i < 26 ; i++)
    {
        arr1[i] = 0;
        arr2[i] = 0;
    }
    int j =0;
    while(a[j] != '\0') //IMPORTANT APPROACH
    {
        arr1[a[j]- 97]++;
        j++;
    }
   j = 0;
   while(b[j] != '\0')
   {
       arr2[b[j] - 97]++;//0 gets initialised to 1 for every occurence
        j++;
   }
   for(int i = 0 ; i < 26 ; i++)
   {
       if(arr1[i] == arr2[i])
       {
           isPerm = true;
       }       
   }
   if(isPerm = true)
   {
       cout<<"true"<<endl;
   }
   else if(isPerm = false)
   {
       cout<<"false"<<endl;
   }
   
    
   
}