void printSolution(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
    cout << endl;
}
bool isEmpty(char grid[N][N], int index, words[index][10], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '-' || grid[i][j] == words[index][0])
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isValidVertical(char grid[N][N], int column, int index, char words[index][10])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (grid[i][column] == '+')
        {
            return false;
        }
        if (grid[i][column] == '-' && grid[i + 1][column] == '-' || grid[i][column] == word[index][i]) // consecutive - signs should be there
        {
            count++;
        }

        // if first word of any word is encountered and is common to word to be filled
    }
    if (count == words[index].length())
    {
        return true;
    }
    return false;
}
bool isValidHorizontal(char grid[N][N], int row, int index, char words[index][10])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == '+')
        {
            return false;
        }
        if (grid[row][i] == '-' && grid[row][i + 1] == '-' || grid[row][i] == word[index][i])
        {
            count++;
        }
    }
    if (count == words[index].length())
    {
        return true;
    }
    return false;
}
void setVertical(char grid[N][N], int column, int index, char words[index][10], &vector<bool> set)

{
    set.size() = words[index].length();
    for (int i = 0; i < N; i++)
    {
        if (isValidVertical(grid, column, index, words))
        {
            if (grid[i][column] == words[index][i])
            {
                set.push_back(false);
            }
            else
            {
                grid[i][column] = words[index][i];
                set.push_back(true);
            }
        }
        else
        {
            set.push_back(false);
        }
    }
}
void setHorizontal(char grid[N][N], int row, int index, char words[index][10], &vector<bool> set)
{
    set.size() = words[index].length();
    for (int i = 0; i < N; i++)
    {
        if(isValidHorizontal(grid,row,index,words){
            if (grid[row][i] == words[index][i])
            {
                set.push_back(false);
            }
            else
            {
                grid[row][i] = words[index][i];
                set.push_back(true);
            }
        }
           else{
            set.push_back(false);
           }
    }
}
void resetVertical(char grid[N][N], int column, vector<bool> set)
{
    // wherever set has been filled as true mark it as '-'

    for (int i = 0; i < N; i++)
    {
        if (set[i] == true)
        {
            grid[i][column] = '-';
        }
    }
}
void resetHorizontal(char grid[N][N], int row, &vector<bool> set)
{
    // for(int i = 0; i < N; i++)
    // {
    //     grid[row][i] = '-';
    // }
    for (int i = 0; i < set.size(); i++)
    {
        if (set[i] == true)
        {
            grid[row][i] = '-';
        }
    }
}
bool crosswordHelper(char grid[N][N], int index, words[index][10])
{
    // constraints
    // if index = no. of words passed -1 it will print the solution

    int row;
    int column;
    vector<bool> set; // passed by reference
    if (index == /*no of words passed */)
    {
        printSolution(grid);
    }
    if (!isEmpty(grid, index, row, column))
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (isValidVertical(grid, column, index, words))
            {
                setVertical(grid, column, index, set);
                if (crosswordHelper(grid, index + 1, words[index][10]))
                {
                    return true;
                }
                else
                {

                    resetVertical(grid, column, set);
                }
                // resets all the words back vertically
            }
            if (isValidHorizontal(grid, row, index, words))
            {
                setHorizontal(grid, row, index, set);
                if (crosswordHelper(grid, index + 1, words[index][10]))
                {
                    return true;
                }
                else
                {
                    resetHorizontal(grid, row, set); // resets all words horizontally
                }
            }
        }
    }
}
void crossword(char grid[N][N], char words[6][10], int index)
{
    crosswordHelper(grid, words[index][10], 0);
}
int main()
{

    // write your code here
    // vector<vector<string>>wordList;
    char grid[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
    char words[6][10];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> words[i][j];
        }
    }
    crossword(grid, words[index][10], 0);
    //     string word_1;
    //     cin>>words;
    //     string word
    //     while(words[i] != '\0')
    //     {
    //         if(words[i] == ";")
    //         {
    //         	index++;
    //             words[index] = words[i+1];

    //             if(crossword(grid,word,index))
    //             {
    //                 break;
    //             }
    //             else{
    //                 continue;
    //             }
    //         }
    //         word.push(words[i]);
    //         i++;
}

return 0;
}