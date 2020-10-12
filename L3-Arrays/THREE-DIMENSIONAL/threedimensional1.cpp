#include <iostream>

using namespace std;

int main (void)
{

    int testNum [2][3][4] = 
    {
        // [0] 1
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

    for (int container = 0; container < 2; ++container)
    {
        for (int row = 0; row < 3; ++row)
        {
            for (int column = 0; column < 4; ++column)
            {
                cout<< "* testNum[" << container << "][" << row << "][" << column << "] = " 
                    << testNum[container][row][column] << endl;
            }
        }
    }
    
}

/*
 * Output:
 * testNum[0][0][0] = 1
 * testNum[0][0][1] = 2
 * testNum[0][0][2] = 3
 * testNum[0][0][3] = 4
 * testNum[0][1][0] = 5
 * testNum[0][1][1] = 6
 * testNum[0][1][2] = 7
 * testNum[0][1][3] = 8
 * testNum[0][2][0] = 9
 * testNum[0][2][1] = 10
 * testNum[0][2][2] = 11
 * testNum[0][2][3] = 12
 * testNum[1][0][0] = 13
 * testNum[1][0][1] = 14
 * testNum[1][0][2] = 15
 * testNum[1][0][3] = 16
 * testNum[1][1][0] = 17
 * testNum[1][1][1] = 18
 * testNum[1][1][2] = 19
 * testNum[1][1][3] = 20
 * testNum[1][2][0] = 21
 * testNum[1][2][1] = 22
 * testNum[1][2][2] = 23
 * testNum[1][2][3] = 24
 * 
 */
