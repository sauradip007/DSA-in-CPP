#include<iostream>
using namespace std;
int main()
{
    char c;
    int count = 0;
    int spaces = 0;
    int nums = 0;
    c = cin.get();
    while( c!= '$')
    {
        for(char i = 'a' ; i <= 'z' ; i++)
        {
            if(c == i)
            {
                 count++;
                 c = cin.get();
            }
        }
       
        if(c == '0' || c == '1' || c== '2' || c == '3' || c == '4' || c=='5' || c == '6' || c == '7' || c == '8' || c == '9'){
            nums++;
            c = cin.get();
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            spaces++;
            c = cin.get();
        }
    }
    cout<<count<<" "<<nums<<" "<<spaces;
}
   

        
    