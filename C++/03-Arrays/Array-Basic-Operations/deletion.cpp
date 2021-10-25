//DELETION OPERATION

/*
 * Deletes an element at the given index. 
 * 
 * Deletion refers to removing an existing element from the array and re-organizing all elements of an array.
 * 
 * Algorithm
 * 
 * Consider LA is a linear array with N elements and K is a positive integer such that K<=N.
 * Following is the algorithm to delete an element available at the Kth position of LA.
 * 
 * 1. Start
 * 2. Set J = k
 * 3. Repeat steps 4 and 5 while J < N 
 * 4. Set LinearArrays[J] - LinearArrays[J + 1]
 * 5. Set J = J + 1;
 * 6. Set N = N - 1;
*/

#include <iostream>

using namespace std;

int main (void)
{
    int LinearArrays
    [] = { 1, 3, 5, 7, 8 };
    int item = 10, k = 3, n = 5;
    int i = 0, j = n;
    cout << "* The original array LinearArrays are : \n";

    for ( i = 0; i < n; i++)
    {
        cout << "* LA" << "[" << i << "]" << " = " << LinearArrays[i] << endl;
    }
    
    j = k;

    while (j < k) // j is 5 and k = 3
    {
        LinearArrays[j - 1] = LinearArrays[j];
        j++;
        //cout << "j   :"<< j << endl;
        //cout << "elJ :" << LinearArrays[j] << endl;
    }

    n--; 
    //cout << n << endl;

    //cout << (LinearArrays[k] = item) << endl;

    cout << "* The array LinearArrays after insertion :\n";

    for (i = 0; i < n; i++)
    {
        cout << "* LA" << "[" << i << "]" << " = " << LinearArrays[i] << endl;
    }

}

/*
 * Output:
 * The original array elements are : 
 * LA[0] = 1
 * LA[1] = 3
 * LA[2] = 5
 * LA[3] = 7
 * LA[4] = 8
 * The array elements after insertion :
 * LA[0] = 1
 * LA[1] = 3
 * LA[2] = 5
 * LA[3] = 7
*/