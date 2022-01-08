#include <iostream>
using namespace std;
void decToBinary(int n)
{
    long binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main()
{
    int n;
    cin>>n;
    if(n == 0)
    {
        long r = 0000;
        cout<<r<<endl;
    }
    else{
    decToBinary(n);
    }
    return 0;
}