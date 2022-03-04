#include<iostream>

#include<algorithm>
using namespace std;

int minsteps_iterative(int n)
{
    
    int *ans = new int[n+1];
    //handle the small problem first
    ans[0] = 0;
    ans[1] = 0;
    for(int i = 2; i < n+1; i++)
    {
        int minusone = ans[i-1];
        int bytwo = INT_MAX,bythree = INT_MAX;
        if(i % 2 == 0)
        {
            bytwo = ans[i/2];
        }
        if(i % 3 == 0)
        {
            bythree = ans[i / 3];
        }
        ans[i] = min(minusone,min(bytwo,bythree))+1;
        
    }
    int answer = ans[n];
    return answer;

}
int minStepsHelper(int n , int*ans)
{
    if(n <=1)
    {
        return 0; // no need to save ans here

    }
    //Check if output already exists
    if(ans[n] != -1)
    {
        //its visited ,we have our answer and we simply have to return it
        return ans[n];
    } 
    //Calculate output
    int x = minStepsHelper(n-1,ans);
    int y = INT_MAX;int z = INT_MAX;
    if(n%2 == 0)
    {
        y = minStepsHelper(n/2,ans);
    }
    if(n % 3 == 0)
    {
        z = minStepsHelper(n/3,ans);
    }
int output = min(x,min(y,z))+1;

//We should save output for future use
ans[n] = output;
return output;

}
int minSteps(int n)
{
    int *ans  = new int [n+1];
    for(int i =0; i < n+1; i++)
    {
        ans[i] = -1;
    }
    return minStepsHelper(n,ans);
}
int countMinStepsToOne(int n)
{
    // Base case
    if (n <= 1)
    {
        return 0;
    }

    // Recursive call
    int x = countMinStepsToOne(n - 1);

    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = countMinStepsToOne(n / 2);
    }

    if (n % 3 == 0)
    {
        z = countMinStepsToOne(n / 3);
    }

    // Calculate final output
    int ans = min(x, min(y, z)) + 1;

    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<countMinStepsToOne(n)<<endl;
}