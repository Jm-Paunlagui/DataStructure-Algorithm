// THREE DIMENSIONAL ARRAYS

/*
 * 
 * You can initialize a three-dimensional array in a similar way like a two-dimensional array.
 *  Here's an example  
 * 
 */

#include <iostream>

using namespace std;

int main (void)
{

    int testNum [2][3][4] = 
    {
        // [0] 1 num
        {
            // 3 rows and 4 columns                   
            { 1, 2, 3, 4 }, 
            { 5, 6, 7, 8 }, 
            { 9, 10, 11, 12 } 
        },
        // [1] 2
        {
            // 3 rows and 4 columns 
            { 13, 14, 15, 16 },
            { 17, 18, 19, 20 }, 
            { 21, 22, 23, 24 }
        }
    };

    cout << testNum[0][2][3] << endl << testNum[1][2][3];
}

/*
 * Output:
 * 12
 * 24
 */
