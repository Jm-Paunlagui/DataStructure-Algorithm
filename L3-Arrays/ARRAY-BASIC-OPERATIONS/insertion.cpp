//INSERTION OPERATION

/**
 * 
 * Adds an element at the given index.
 * 
 * Insert operation is to insert one or more data elements into an array. 
 * Based on the requirement, a new element can be added at the beginning,
 * end, or any given index of array.
 */

#include <iostream>

using namespace std;

int main (void)
{
    int LinearArrays
    [] = { 1, 3, 5, 7, 8 };
    int item = 10, k = 3, n = 5;
    int i = 0, j = n;
    cout << "* The original array elements are : \n";

    for ( i = 0; i < n; i++)
    {
        cout << "* LA" << "[" << i << "]" << " = " << LinearArrays[i] << endl;
    }
    n++;

    while (j >= k) // j is 5 and k = 3
    {
        LinearArrays[j + 1] = LinearArrays[j];
        j--;
        //cout << "j   :"<< j << endl;
        //cout << "elJ :" << LinearArrays[j] << endl;
    }

    LinearArrays[k] = item;

    //cout << (LinearArrays[k] = item) << endl;

    cout << "* The array elements after insertion :\n";

    for (i = 0; i < n; i++)
    {
        cout << "* LA" << "[" << i << "]" << " = " << LinearArrays[i] << endl;
    }
    
    
}

/*
 * Output:
 * The original array LinearArrays are : 
 * LA[0] = 1
 * LA[1] = 3
 * LA[2] = 5
 * LA[3] = 7
 * LA[4] = 8
 * The array LinearArrays after insertion :
 * LA[0] = 1
 * LA[1] = 3
 * LA[2] = 5
 * LA[3] = 10
 * LA[4] = 7
 * LA[5] = 8
*/