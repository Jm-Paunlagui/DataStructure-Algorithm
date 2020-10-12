//UPDATE OPERATION

/**
 * Updates an element at the given index.
 * 
 * Update operation refers to updating an existing element from the array at a given index.
 * 
 * ALGORITHM
 * 
 * Consider LA is a linear array with N elements and K is a positive integer such that K<=N. 
 * Following is the algorithm to update an element available at the Kth position of LA.
 * 
 * 1. Start
 * 2. Set LinearArrays[K - 1] = Item
 * 3. Stop
 * 
 */

#include <iostream>

using namespace std;

int main (void)
{
    int LinearArrays[] = { 1, 3, 5, 7, 8};
    int item = 10, n = 5, k = 3, i, j;

    cout << " * The original array elements are : \n";

    for (i = 0; i < n; i++)
    {
        cout << " * LinearArray [" << i << "] = " << LinearArrays[i] << endl;
    }

    LinearArrays [k - 1] = item;

    cout << " * The array elements after update : \n"; 

    for (i = 0; i < n; i++)
    {
        cout << " * LinearArrays [" << i << "] = " << LinearArrays[i] << endl;
    }
    
}

/*
 * Output:
 * The original array elements are : 
 * LinearArray [0] = 1
 * LinearArray [1] = 3
 * LinearArray [2] = 5
 * LinearArray [3] = 7
 * LinearArray [4] = 8
 * The array elements after update :
 * LinearArrays [0] = 1
 * LinearArrays [1] = 3
 * LinearArrays [2] = 10
 * LinearArrays [3] = 7
 * LinearArrays [4] = 8 
*/