#include <iostream>
using namespace std;
void print(int a[], int size)
{
    if (size == 0)
    {
        return;
    }
    print(a + 1, size - 1);
    print(a, size);
}
int main()
{
    int a[3] = {15,20,12};
    print(a,3);
}