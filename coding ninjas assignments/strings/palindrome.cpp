#include<iostream>
using namespace std;
int length(char a[])
{
    int count = 0;
    for(int i = 0 ; a[i] != '\0';i++)
    {
        count++;

    }
    return count;
}
bool checkpal(char a[])
{
    int n = length(a);
    if(n==1)
    {
        return false;
    }
    else{
   
    for(int i = 0 ; a[i] != '\0' ; i++)
    {
        if(a[i] == a[n-i+1])
        {
            return true;
        }
    }
    return false;
    }
}
int main(){
    char a[7];
    cin>>a;
    cout<<checkpal(a)<<endl;
    

}