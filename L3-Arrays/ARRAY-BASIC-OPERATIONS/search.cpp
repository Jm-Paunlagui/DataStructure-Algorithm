// SEARCH OPERATION
/**
 * Searches an element using the given index or by the value.
 * 
 * You can perform a search for an array element based on its value or its index.
 * 
 * Algorithm
 * 
 * Consider LA is a linear array with N elements and K is a positive integer such that K<=N. 
 * Following is the algorithm to find an element with a value of ITEM using sequential search
 * 
 * 1. Start
 * 2. Set J = 0
 * 3. Repeat steps 4 and 5 while J < N
 * 4. IF LinearArrays[J] is equal ITEM THEN GOTO STEP 6
 * 5. Set J = J + 1
 * 6. PRINT J, ITEM
 * 7. Stop
 */

#include <iostream>

using namespace std;

int main (void)
{
    int LinearArrays[] = { 1, 3, 5, 7, 8};
    int item = 5, n = 5, i = 0, j = 0;

    cout << "The original array elements are : \n";

    for (i = 0; i < n; i++)
    {
        cout << "* LinearArray [" << i << "] = " << LinearArrays[i] << endl;
    }

    while( j < n )
    {
        if (LinearArrays[j] == item)
        {
            break;
        }
        j++;
    }

    cout << "* Found element ( " << item << " ) at position\n" << j << endl;
    
}

/**
 * Output
 * The original array elements are : 
 * LinearArray [0] = 1
 * LinearArray [1] = 3
 * LinearArray [2] = 5
 * LinearArray [3] = 7
 * LinearArray [4] = 8
 * Found element ( 5 ) at position
 * 2
 * 
*/