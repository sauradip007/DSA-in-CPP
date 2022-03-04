#include<iostream>
#include<cstring>
using namespace std;
void printSolution(int ** solution, int n){
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cout<<solution[i][j]<<" ";
        }
    }cout<<endl;
}
void mazeHelp(int maze[][20], int n, int **solution, int x, int y){ // x and y denote current position of row and column respectively , solution is the solution matrix and n denotes the number of rows and columns present


//think of constraints

//we print when we have reached the destination point when all paths have been explored
if( x == n-1 && y == n-1)
{
    solution[x][y] = 1; //including myself in the current position
    printSolution(solution,n);
    solution[x][y] = 0;
    return;
    //print and return
} //solution reached
if(x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
{
    return;
}//simply return


solution[x][y] = 1; //wherever we are currently we insert 1 and then we need to check up down left anfd right
mazeHelp(maze,n,solution,x-1,y);
mazeHelp(maze,n,solution,x+1,y);
mazeHelp(maze,n,solution,x,y+1);
mazeHelp(maze,n,solution,x,y-1);
//after exploring all the paths i put current position as 0 as visited
solution[x][y] = 0;
return;

}
// void ratInAMaze(int maze[][20], int n)
// {
//     int** solution = new int *[n];
//     for(int i  = 0 ; i < n ; i++)
//     {
//         solution[i] = new int [n];
//     }
//     mazeHelp(maze,n,solution,0,0);
// }
int main()
{
    int n;
    cin >> n;
    int maze[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    //     Initialising 2d solution array
    int **solution = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }
    mazeHelp(maze, n, solution, 0, 0);

    return 0;
}


// My approach
// void printSolution(int** solution, int n)
// {
//     for(int i = 0; i < n ; i++)
//     {
//         for(int j = 0; j < n ; j++)
//         {
//             cout<<solution[i][j]<<" ";
//         }
//     }cout<<endl;
// }
// void mazehelp(int maze[][20], int n, int** solution, int x, int y)
// {
//     if(x == n-1 && y == n-1)
//     {
//         solution[x][y] = 1;
//         printSolution(solution,n);
//         solution[x][y] = 0;
//         return;
//     }
//     if(x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
//     {
//         return;
//     }
//     solution[x][y] = 1;
//     mazehelp(maze,n,solution,x-1,y);//up
//     mazehelp(maze,n,solution,x+1,y); //down
//     mazehelp(maze,n,solution,x,y+1); //right
//     mazehelp(maze,n,solution,x,y-1); //left
//     //after all possible paths visited come back to current position and make it 0
//     solution[x][y] = 0;
//     return;
// }
// void ratinmaze(int maze[][20], int n)
// {
//     int ** solution = new int* [n];
//     for(int i = 0; i < n; i++)
//     {
//         solution[i] = new int [n];
//     }
//     mazehelp(maze,n,solution,0,0);
// }