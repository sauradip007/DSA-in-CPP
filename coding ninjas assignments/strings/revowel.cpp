#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    int i = 0;
    int j = strlen(a)-1;
    while(i < j)
    {
        if(a[i] != 'a' ||a[i] != 'e'|| a[i] != 'i'|| a[i] != 'o'|| a[i] != 'u')
        {
            i++;
        }
        else{
            if(a[j] != 'a' ||a[j] != 'e'|| a[j] != 'i'|| a[j] != 'o'|| a[j] != 'u')
            {
                j--;
            }
            else{
                char temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                
            }
           
            
        }
        
        
        
    }
    /*for(int i = 0 ; a[i] != '\0' ; i++)
    {
        cout<<a[i];
    }*/
     cout<<a;
}