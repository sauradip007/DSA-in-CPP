#include<iostream>
#include<cstring>
using namespace std;
// int board[11][11]; //creating a board of 11 x 11
// bool isPossible(int n, int row, int column)
// {
//     //which row and column you are currently present in
//     // 1) when we are placing the queen in the board we have to check:
//                 // i) if any queen is present in the UPPER diagonals for it
//                 // ii) if any queen is present in the UPPER part of it (vertically)
//     for(int i = row-1; i >= 0; i--)
//     {
//         // Same column
//         if(board[i][column] == 1) //queen exists in upper column
//         {
//             return false;
//         }
//     }
//     // Upper left diagonal
//     for(int i = row-1, j = column -1; i >= 0 && j >= 0; i--,j--)
//     {
//         if(board[i][j] == 1) //queen at upper left diagonal
//         {
//             return false;
//         }
//     }
//     // Upper right diagonal
//     for(int i = row - 1, j = column+1; i >= 0 && j < n; i--,j++)
//     {
//             if(board[i][j] == 1)
//             {
//                 return false;
//             }
//     }
//     return true;
// }
// void nQueenHelper(int n, int row){ //which row , row represents current row being traversed and n represents no of rows in the board
//     if(row == n) //this corresponds to the case where 5th row has been reached for 4x4 matrix
//     {
//         //We have reached some solution
//         //print the matrix or board obtained
//         //return
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 cout<<board[i][j]<<" ";
//             }
//         }
//         cout<<endl;
//         return; //as discussed , when 5th row for 4x4 matrix is reached , it simmply prints the matrix and returns back to the first case
//     }
// //else place at all possible positions and move to the smaller problem
//     for(int j = 0; j < n; j++) //traversing columns row wise within the matrix
//     {
//         if(isPossible(n,row,j)){
//             board[row][j] = 1; //inserted at THAT column now go downwards and check for the lower row , for this call in recursion(smalll problem)
//             nQueenHelper(n,row+1);
//             //now this row has gone downward and explored all possible paths, it goes back up now (backtracks) and marks this column as explored
//             board[row][j] = 0; //its now visited
//         }
//     }
//     return;
// }
// void placeNQueens(int n){ //n denotes the no of queens to be placed
// memset(board,0,11*11*sizeof(int));
// nQueenHelper(n,0);

// }
// int main()
// {

// }

// My approach
int board[11][11];
bool isPossible(int n, int row, int column)
{
    //vertical check
    for(int i = row - 1; i >= 0 ; i--)
    {
        if(board[i][column] == 1)
        {
            return false;
        }
    }
    //upper right
    for(int i = row-1, int j = column-1; i  >= 0 && j >= 0; i--,j--)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    //upper left
    for(int i = row-1, int j = column+1; i >= 0 && j < n; i--,j++)
    {
        if(board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void nqueenhelp(int n , int row)
{
    if (row == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                cout<<board[i][j]<<" ";
            }
        }cout<<endl;
        return;
    }

    for(int j = 0; j < n ; j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j] = 1;
            nqueenhelp(n,row+1);
            board[row][j] = 0;
        }
    }
    return;




    
}
void placeNQueens(int n)
{ // n denotes the no of queens to be placed
    memset(board, 0, 11 * 11 * sizeof(int));
    nqueenhelp(n, 0);
}