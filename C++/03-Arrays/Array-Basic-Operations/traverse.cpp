// TRAVERSE OPERATION

/**
 * Print all the array elements one by one.
 * 
 * This operation is to traverse through the elements of an array.
 */

#include <iostream>

using namespace std;

int main (void)
{
    int LinearArrays[] = { 1, 3, 5, 7, 8 };
    //int item = 10, k = 3, j = n;
    int i = 0, n = 5;
    cout << "* The original array elements are : \n";

    for ( i = 0; i < n; i++)
    {
        cout << "* LA" << "[" << i << "]" << " = " << LinearArrays[i] << endl;
    }
    
}

/**
 * Output:
 * The original array elements are : 
 * LA[0] = 1
 * LA[1] = 3
 * LA[2] = 5
 * LA[3] = 7
 * LA[4] = 8
 */