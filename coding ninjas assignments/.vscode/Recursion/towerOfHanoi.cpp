#include<iostream>
using namespace std;
void towerOfHanoi(int n, char source, char helper, char destination)
{
    // source = 'a';
    // helper = 'b';
    // destination = 'c';
    if(n==1)
    {
        cout<<source<<" "<<destination<<endl;
        return;
    }
    towerOfHanoi(n-1,source, destination, helper);
    cout<<source<<" "<<destination<<endl;
    towerOfHanoi(n-1,helper,source,destination);
}
 int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}