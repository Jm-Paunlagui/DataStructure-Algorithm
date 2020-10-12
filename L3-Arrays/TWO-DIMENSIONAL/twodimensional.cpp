// TWO DIMENSIONAL ARRAY

/*
 * The simplest form of the multi-dimensional array is the two-dimensional array. 
 * A two-dimensional array is, in essence, a list of one-dimensional arrays. 
 * To declare a two-dimensional integer array of size x,y, you would write something as follows
 * 
 *    ~ type arrayName [ x ] [ y ];
 * 
 *  Where type can be any valid C++ data type and arrayName will be a valid C++ identifier.
 * 
 *      A two-dimensional array can be think as a table,
 *       which will have x number of rows and y number of columns. 
 *      A 2-dimensional array a, which contains three rows and four columns can be shown as below
 * 
 *            Column 0  Column 1  Column 2  Column 3       
 *      Row 0  a[0][0]   a[0][1]   a[0][2]   a[0][3]
 *      Row 1  a[1][0]   a[1][1]   a[1][2]   a[1][3]
 *      Row 2  a[2][0]   a[2][1]   a[2][2]   a[2][3]
 * 
 * Note: Thus, every element in array a is identified by an element name of the form a[ i ][ j ], where a is the name of the array, 
 *       and i and j are the subscripts that uniquely identify each element in a.
 * 
 * INITIALIZING TWO-DIMENSIONAL ARRAYS
 *      
 *      Multi-dimensioned arrays may be initialized by specifying bracketed values for each row. 
 *      Following is an array with 3 rows and each row have 4 columns.
 *      
 *      int num [3][4] = { { 0, 1, 2, 3 }, // 1st row
 *                         { 4, 5, 6, 7 },  // 2nd row
 *                         { 8, 9, 10, 11 } // 3rd row
 *                       };
 *  Note: The nested braces, which indicate the intended row, are optional. 
 *  The following initialization is equivalent to previous example
 * 
 * ACCESSING TWO-DIMENSIONAL ARRAY ELEMENTS
 *      
 *      An element in 2-dimensional array is accessed by using the subscripts, i.e., 
 *      row index and column index of the array. For example:
 *              
 *      int val = a[2][3]
*/

#include<iostream>

using namespace std;

int main (void)
{
    // An array with 5 row and 2 columns.
    int nums [5][2] = 
    {
        { 0, 0}, 
        { 1, 2},
        { 2, 4},
        { 3, 6},
        { 4, 8}
    };

    for (int first = 0; first < 5; first++)   
        for (int second = 0; second < 2; second++)
        {
            cout << "* nums [" << first << "] [" << second << "]: ";
            cout << nums[first][second] << endl;
        }
    
}

/* 
 * Output:
 * nums [0] [0]: 0
 * nums [0] [1]: 0
 * nums [1] [0]: 1
 * nums [1] [1]: 2
 * nums [2] [0]: 2
 * nums [2] [1]: 4
 * nums [3] [0]: 3
 * nums [3] [1]: 6
 * nums [4] [0]: 4
 * nums [4] [1]: 8
*/