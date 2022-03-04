#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
// int minCost(int ** input, int m, int n, int row, int col)
// {
//     //it stops when he reaches the end i.e.
//   if(row == m-1 || col == n-1)
//   {
//       return input[row][col]+input[0][0];
//   } //fix out of bound conditions

//     //person is at a[0][0]
    
//     //find the min of up down and diagonal as those are the possible paths it can take
//     // int cost1 = min(input[row][col + 1], min(input[row+1][col], input[row+1][col+1]));
//     // int a = 0;int b = 0; int c = 0;
//     int a =  minCost(input,m,n,row+1,col);//up
//     int b =  minCost(input,m,n,row,col+1); //down
//     int c =minCost(input,m,n,row+1,col+1); //diagonal
//     return min(a,min(b,c));



// }
//DP
int min_cost_DP(int **input, int m, int n)
{
  int **output = new int *[m];
  for (int i = 0; i < m; i++)
  {
    output[i] = new int[n];
  }
  // It is a bottom up approach so fill the last destination first i.e. at m-1 n-1
  output[m-1][n-1] = input[m-1][n-1]; //last cell will be the value in matrix itself

  //Now we have to fill the last row which is out of bound from right to left
  for(int j = n-2 ; j >= 0; j--){
    output[m-1][j] = output[m-1][j+1] + input[m-1][j];
  }
  //Fill last column which is the rightmost column which is out of bound
  for(int i = m-2; i >= 0 ; i--)
  {
    output[i][n-1] = output[i+1][n-1] + input[i][n-1];
  }
  //Now fill all the remaining cells using DP logic
  //They will be filled from right to left
  for(int i = m-2; i >= 0; i--)
  {
    for(int j = n-2; j >= 0 ; j--)
    {
      int x = output[i+1][j];
      int y = output[i][j+1];
      int z = output[i+1][j+1];
      int ans = min(x,min(y,z)) + input[i][j];

      output[i][j] = ans;
    }
  }
  return output[0][0];
}
    // memoization
    int min_cost_mem(int **input, int m, int n, int row, int col, int **output)
{
  if(row == m-1 && col == n-1)
  {
    return input[row][col];
  }
  if(row >= m || col >= n)
  {
    return INT_MAX;
  }
  //Check if answer already exists
  if(output[row][col] != -1)
  {
    return output[row][col];
  }

  // Recursive calls
  int a = min_cost_mem(input, m, n, row + 1, col,output);
  int b = min_cost_mem(input, m, n, row, col + 1,output);
  int c = min_cost_mem(input, m, n, row + 1, col + 1,output);
  int ans =  min(a, min(b, c)) + input[row][col];
  //Save this answer in output array
  output[row][col] = ans;
  return output[row][col];
}
int minCost(int **input, int m, int n, int row, int col)
{
  // it stops when he reaches the end i.e.

  if (row == m - 1 && col == n - 1)
  {
    return input[row][col];
  }
  if (row + 1 > m || col + 1 > n)
  {
    return INT_MAX;
  }
  // person is at a[0][0]

  // find the min of up down and diagonal as those are the possible paths it can take
  //  int cost1 = min(input[row][col + 1], min(input[row+1][col], input[row+1][col+1]));
  // int a = INT_MAX; int b = INT_MAX; int c = INT_MAX;
  int a = minCost(input, m, n, row + 1, col);
  int b = minCost(input, m, n, row, col + 1);
  int c = minCost(input, m, n, row + 1, col + 1);
  return min(a, min(b, c)) + input[row][col];
}

int minCostPath(int **input, int m, int n)
{
  // Write your code here
//creating 2d array
int **output = new int*[m];
for(int i = 0; i < n; i++)
{
  output[i] = new int[n];

}
//initialising it to -1
for(int i = 0; i < m ; i++)
{
  for(int j = 0; j < n; j++)
  {
    output[i][j] = -1;
  }
}
  return minCost(input, m, n, 0, 0);
}