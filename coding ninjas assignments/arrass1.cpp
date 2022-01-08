#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    int j = 1;
    while(i < n && j <= n)
    {
      if(i <= (n-1)/2)
      {
          if(j % 2 != 0)
          {
          arr[i] = j;
          }

      }
      if(i > (n-1)/2)
      {
          if(j % 2 == 0)
          {
          arr[i] = j;
          }
      }
      i++;
      j++;
    }
  
    
    for(int j = 0 ; j < n ; j++)
    {
        cout<<arr[j]<<" ";
    }cout<<endl;
}