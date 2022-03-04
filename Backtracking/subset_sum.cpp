#include<iostream>

using namespace std;

// void subsetsum(int * arr, int n, int k,int index,int sum)
// {
//     //Here sum is the sum we are going on adding in the array
//     //initially we are taking total to be entire sum of the array
//     sum += arr[index];
//     int total;
//     for(int i = 0; i < n; i++)
//     {
//         total += arr[i];
//     }
//     //Now in our solution tree there aare 2 cases
//     // 1) we consider that element in array
//     //  2) we dont consider that element

//     //We are using a DFS approach so we are considering the element here

//     // in our bounding func
//     // int sum = 0;
//     if(index == n-1)
//     {
//         return;
//     }
//     if(sum + arr[index+1] > k)
//     {
//         return; //if sum is greater we stop
//         //not including
//         subsetsum(arr+1,n-1,k,index,sum);
//     }
//     //function call will be something like
//     subsetsum(arr+1,n-1,k-arr[index],index,sum+arr[index]);
    
// }
// int subsum(int *arr, int n ,int k, int sum, int index)
// {
//     int count = 0;
//     if(index == n-1)
//     {
//         return;
//     }
//     subsum(arr,n,k-arr[index],sum+arr[index],index+1); //considering
//     subsum(arr,n,k,sum,index+1); //not considering
// }
void subsetk(int * arr, int n , int k, int index,int sum, int total,int &count)
{
    //2 vals in each tree node, sum and total value

    //index keeps track of which element is being considered
//setting count of such elements to 0

    //calculating total
    // for (int i = index; i < n; i++)
    // {
    //     total += arr[i];
    // }

    // if sum becomes equal to k then a subset is found
    if (sum == k)
    {
        count++;
        return;
    }
    // int count;
    if (index >= n)
    {
        return;
}
//initialising total



//sum is the rq.d sum i wanna add up and get k

    // //considering
    // subsetk(arr,n,k,index+1,sum+arr[index],total-arr[index]);

    //bounding function 1: sum of the weights included so far(sum) and the val of next index sum should be less than k
    if(sum  > k)
    {
        return;
        
    }
    // if(sum + arr[index+1] > k && index < n-1)
    // {
    //     return;
    // }
  
    int total_2 = 0;
    for(int j = index+1 ; j < n; j++)
    {
        total_2 += arr[j];
    }
    //if sum obtained till now
    if( sum + arr[index] + total_2 < k)
    {
        return;
    }
 
    //  call including
    // considering
    subsetk(arr, n, k, index + 1, sum + arr[index], total - arr[index],count);
    // call not including
    subsetk(arr, n, k, index + 1, sum, total - arr[index],count);
    // boundary function 2
    //   so far our sum what we've included (sum) and sum of remaining vals should be greater than k
    /*---------*/
    // Next approach
    // bounding functions behave as base cases and include and not included are simply called
  
}
// int  subsetk(int *arr, int n, int k, int index, int sum, int total, int count)
// {
//     // 2 vals in each tree node, sum and total value

//     // index keeps track of which element is being considered
//     // setting count of such elements to 0
//     //  int count;
//     if (index == n - 1)
//     {
//         return count;
//     }

//     // sum is the rq.d sum i wanna add up and get k

//     // //considering
//     // subsetk(arr,n,k,index+1,sum+arr[index],total-arr[index]);

//     // bounding function 1: sum of the weights included so far(sum) and the val of next index sum should be less than k
//     if (sum + arr[index + 1] <= k)
//     {
//         return count;
//     }
//     int total_2 = 0;
//     for (int j = index + 1; j < n; j++)
//     {
//         total_2 += arr[j];
//     }
//     if (sum + total_2 > k)
//     {
//         return count;
//     }
//     // if sum becomes equal to k then a subset is found
//     if (sum == k)
//     {
//         count++;
//     }
//     //  call including
//     // considering
//     count = subsetk(arr, n, k, index + 1, sum + arr[index], total - arr[index], count);
//     // call not including
//     count = subsetk(arr, n, k, index + 1, sum, total - arr[index], count);
//     // boundary function 2
//     //   so far our sum what we've included (sum) and sum of remaining vals should be greater than k
//     /*---------*/
//     // Next approach
//     // bounding functions behave as base cases and include and not included are simply called
//     return count;
// }
int subsetsum(int arr[], int n , int k, int index)
{
	//sort(arr,arr+n);
    if(index==n){
        if(k==0)
        {
            return 1;
        }
        else{
        return 0;
        }
    }
    int ans=0;
    if(arr[index]<=k){
      ans+=subsetsum(arr,n,k-arr[index],index+1);
    }
    ans+=subsetsum(arr,n,k,index+1);
    return ans;
}
int main()
{
    int size;
    cin>>size;
    int *arr = new int [size];
    int k;
    cin>>k;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int total = 0;
    for(int i = 0;i < size; i++)
    {
        total += arr[i];
    }
    int count = 0;
    subsetk(arr,size,k,0,0,total,count);
    cout<<count;

    // cout << "subsets are : " << subsetk(arr, size, k, 0, 0, total,0) << endl;
    // int t;
    // cin>>k>>t;
    // while(t--)
    // {
    //     cout<<subsum(arr,size,k,0,0)<<endl;
    //     //  subsetsum(arr,size,k,0,0);
    //     int total = 0;
    //     for(int i = 0; i < size; i++)
    //     {
    //         total += arr[i];
    //     }
    //     cout<<subsetk(arr,size,k,0,0,total)<<endl;
    // }
}
int subsum(int arr[], int n, int k, int index)
{
    if(index == n)
    {
        if(k == 0)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    int ans = 0;
    if(arr[index] <= k)
    {
        ans += subsum(arr,n,k-arr[index],index+1);//including
    }
    ans += subsum(arr,n,k,index+1);
    //not including 
    return ans;
}