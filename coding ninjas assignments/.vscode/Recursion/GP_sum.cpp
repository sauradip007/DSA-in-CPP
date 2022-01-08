#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;
double sum(int k)
{
  
    double k_term =(1/pow(2,k));
    double smallOutput;
    double sum = 0;
    for(int i = 0 ; i <= k-1 ; i++)
    {
        sum+= (1/pow(2,i));
    }
    smallOutput = sum;
   
    return smallOutput + k_term;
   

}
int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout<<sum(k)<<endl;
}