#include<iostream>
#include<algorithm>
using namespace std;
int knapsack_DP(int *weights, int *values, int n, int maxWeight, int**output)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= maxWeight; i++)
    {
        output[i] = new int[maxWeight + 1];
      
    }

    //At 0,0 the value of 2-D array will be 0
    output[0][0] = 0;
    //filling first row with 0 and first col with 0
    for(int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
        
    }
    for(int j = 0; j <= maxWeight; j++)
    {
        output[0][j] = 0;
    }
    //Filling the rest of the array
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxWeight; j++)
        {
            if(weights[i-1] < j)
            {
                output[i][j] = output[i-1][j];
            }
            int a = output[i-1][j-weights[i]] + values[i];
            int b = output[i-1][j];
            output[i][j] = max(a,b);
        }
    }
    return output[n][maxWeight];

}
int knapsack_mem(int *weights, int *values, int n, int maxWeight, int **output)
{
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }
    if(output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }
    if(weights[0] > maxWeight)
    {
        return knapsack_mem(weights+1,values+1,n-1,maxWeight,output);
    }
    int a = knapsack_mem(weights+1,values+1,n-1,maxWeight-weights[0],output)+values[0];
    int b = knapsack_mem(weights+1,values+1,n-1,maxWeight,output);
    output[n][maxWeight] = max(a,b);
    return output[n][maxWeight];
}
int knapsack_DP(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
      
    }

    //At 0,0 the value of 2-D array will be 0
    //filling first row with 0 and first col with 0
    for(int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
        
    }
    for(int j = 0; j <= maxWeight; j++)
    {
        output[0][j] = 0;
    }
    //Filling the rest of the array
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= maxWeight; j++)
        {
            
            
            output[i][j] = output[i-1][j];
            if(j>=weights[i-1])
            {
            int a = output[i-1][j-weights[i-1]] + values[i-1];
            int b = output[i][j];
            output[i][j] = max(a,b);
            }
        }
    }
    return output[n][maxWeight];
    
}
int knapsack_DP(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
    }

    // At 0,0 the value of 2-D array will be 0
    // filling first row with 0 and first col with 0
    for (int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
    }
    for (int j = 0; j <= maxWeight; j++)
    {
        output[0][j] = 0;
    }
    // Filling the rest of the array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {

           
            if (j >= weights[i - 1])
            {
                int a = output[i - 1][j - weights[i - 1]] + values[i - 1];
                int b = output[i][j];
                output[i][j] = max(a, b);
            }
            output[i][j] = output[i - 1][j];
        }
    }
    return output[n][maxWeight];
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **output = new int * [n+1];
    for(int i = 0; i <= n; i++)
    {
        output[i] = new int [n+1];
        for(int j = 0; j <= maxWeight; j++)
        {
            output[i][j] = -1;
        }
    }
    // write your code here
    // max weight is given
    if (n == 0)
    {
        return 0;
    }
    if(maxWeight == 0)
    {
        return 0;
    }
    if (weights[0] > maxWeight)
    {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
    int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}