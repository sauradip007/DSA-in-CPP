#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char input[100];
    cin.getline(input, 100);
    int i = 0, len = strlen(input);
    int j = len - 1;

    while (i < j)
    {

        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;

        i++;
        j--;
    }
    //reversed string , now tinputke word wise
   
    cout << input;
}