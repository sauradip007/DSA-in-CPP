#include<iostream>
using namespace std;
void allprefix(char input[])
{
    for(int i = 0 ; input[i] != '\0'; i++)
    {
        for(int j = 0; j <= i ; j++)
        {
            cout<<input[j];
        }
        cout<<endl;
    }
}
int main()
{
    char input[100] = "abcd";
    allprefix(input);
    

}