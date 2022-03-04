#include<iostream>
#include<string>
using namespace std;
#define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col)
{
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
           if(grid[i][j] == 0)
           {
               row = i;
               col = j; 
               //updates the position to the position of empty space within the sudoku
               return true;
           }
          
       }
   }
   return false; //if empty space is not found within the entire grid
}
bool isSafeRow(int grid[N][N], int row, int num)
{
    for(int i = 0; i < N; i++)
    {
        if(grid[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeCol(int grid[N][N], int column, int num)
{
    for(int i = 0; i < N; i++)
    {
        if(grid[i][column] == num)
        {
            return false;
        }
    }
    return true;

}
bool isSafeGrid(int grid[N][N], int row, int column, int num)
{
    //checking for the 3x3 matrix
    int rowFactor = row - (row % 3);
    int colFactor = column - (column % 3);
    for(int i = 0; i < 3 ; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            if(grid[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N], int row, int column, int num) //checks if the no to be entered is present in the current row current column or the curretn 3x3 matrix its in
{
    if(isSafeRow(grid,row,num) && isSafeCol(grid,column,num) && isSafeGrid(grid,row,column,num)){
        return true;
    }
return false;
}
bool solveSudoku(int grid[N][N]){
    int row,column;
    if(!findEmptyLocation(grid,row,column))//row and column here get updated w values of row and column from findempty function as it is passed by reference
    {
        return true;
    }
    for(int i = 1; i <=9 ; i++)//filling values from 1 to 9
    {
        if(isSafe(grid,row,column,i)){
            grid[row][column] = i;
            //placing appropriate value at that empty location
            if(solveSudoku(grid))
            {
                return true;
                //if it is further solvable on calling the function,the sudoku has been solved return true
            }
            //otherwise make that particular row and column value 0 and check for the entire grid for a different set of values
            grid[row][column] = 0;
        }
    }
    return false; //if it comes out of loop and is not been able to solve for all values from 1 - 9 then sudoku is not solvable
}
int main()
{
    int grid[N][N];
    
    for(int i = 0 ;i < N; i++)
    {
        string s;
        cin>>s;
        for(int j = 0; j < s.length(); j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }
    solveSudoku(grid);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<grid[i][j]<<" ";
        }
    }cout<<endl;
    return 0;
}
