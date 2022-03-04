#include<iostream>
#include<string>
using namespace std;
// int permutation(string input, string output[])
// {
//     //1st approach
//     if(input.empty())
//     {
//         output[0] = " ";
//         return 0;
//     }
// int smallOutput = permutation(input.substr(1),output);
//     for(int i = 0; i < smallOutput; i++)
//     {


//         for(int j = 0; j < smallOutput[i].length(); j++)
//         {
//             smallOutput[i].substr(0,j) + input[0] +  smallOutput[i].substr(j);
//         }
//         // //one char at a time
//         // //in string 'adg' 'a' is the first char , dg will be the remaining chars for i = 0
//         //  smallOutput = permutation(input.substr(0,i-1)+input.substr(i+1,input.size()), output); // gives dg and gd
//         // output[i] += input[i]; //starting character appeneded to strings returned by recursion call
//     }
//     return smallOutput;
// }
//try second logic
int returnPermutations(string input, string output[])
{
   
    if(input.length() == 0)
    {
        output[0] = " ";
        return 1;
    }
    string helpArr[10000];
    //call small output for 'dg' in 'adg'
    int smallOutput = returnPermutations(input.substr(1), helpArr);
    //'dg' and 'gd' populates the output string array
    //'_dg' 'd_g' 'dg_' append a to each
    //no. of blank spaces will be length of string+1
    int k = 0;
    for(int i = 0; i < smallOutput; i++)
    {
        for(int j = 0; j < helpArr[i].length(); j++)
        {
            output[k] = helpArr[i].substr(0,j) + input[0] + helpArr[i].substr(j);
            k++;
        }
        
    }
    return k;
    
}