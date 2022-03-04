#include <iostream>
#include <vector>
    using namespace std;
    int main()
    {

        /* Here we tell how many rows
        the 2D vector is going to have. */
        int row = 5;

        /* We define the number of values
        each row is supposed to have. */
        int column[] = {5, 3, 4, 2, 1};

        /*
        We now create a vector of vector with size
        equal to row.
        */

        vector<vector<int>> vec(row);
        /*
        On line 21 we created a 2D vector and assigned
        it a capacity of "row"(in this case 5) units.
        */

        /*
        Now we will proceed to create the structure of
        our 2D vector by assigning the value of rows and
        columns through a nested for loop.
        */

        for (int i = 0; i < row; i++)
        {
            /* Declaring the size of the column. */
            int col = column[i];

            /*
            On the 43rd line we declare the
            i-th row to the size of the column.
            We create a normal vector of capacity "col" which
            in every iteration of the for loop will define the
            values inside of each row.
            */
            vec[i] = vector<int>(col);
            for (int j = 0; j < col; j++)
            {
                vec[i][j] = j + 1;
            }
        }

        /*
        We now finally use a simple nested for loop
        to print the 2D vector that we just created above.
        */

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    /*
   In the case of a normal vector we initialize it as:

   1. vector<datatype> variable_name

   Now in the case of a 2D vector all we do is create
   a vector of datatype vector.

   We simply replace "datatype" with "vector<int>":

   1. vector<vector<int>> variable_name

   That's literally it! We just created a 2D vector!
   On line 23 below we declare an actual 2D vector
   named "vect".
   */

//   vector<vector<int>>p ={
//       {1,2,3},
//       {4,5,6},
//       {7,8,9}
//   };
    // vector<vector<int>> vect{
    //     /* Element one with 2 values in it. */
    //     {1, 2},

    //     /* Element two with 3 values in it. */
    //     {4, 5, 6},

    //     /* Element three with 4 values in it. */
    //     {7, 8, 9, 10}};
    // vector<vector<int>>vect{
        
    // }
   

//     for (int i = 0; i < vect.size(); i++)
//     {
//         cout<<"This is the "<<i<<"th array"<<endl;
//         for (int j = 0; j < vect[i].size(); j++)
//         {
//             cout << vect[i][j] << " ";
//         }
//         cout << endl;
//   }



// Another representation
//     int row = 5;
//     int column[] = {5, 3, 4, 2, 1};
//     vector<vector<int>> vec(row);

// }