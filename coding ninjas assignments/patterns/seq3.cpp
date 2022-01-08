#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i = 0;
    int prev;
    cin>>prev;
    int curr;
    bool isDecrease = true;
    while(i < n-1)
    {
        cin>>curr;
         if(prev ==  curr)
        {
            isDecrease  = false;
            if (prev > curr)
        {
            isDecrease;
        }


        }
        else if ( prev < curr)
        {
            isDecrease = false;
        }
        else if (prev > curr)
        {
            isDecrease;
        }
        i++;
    }
    if(isDecrease = true)
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}