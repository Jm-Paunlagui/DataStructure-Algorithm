// ONE DIMENSIONAL ARRAY

/*
 * The arraySize must be an integer constant greater than zero and type can be any valid C++ data type. 
 * For example, to declare a 10-element array called balance of type double, use this statement
 * 
 * Initializing arrays
 * 
 * You can initialize C++ array elements either one by one or using a single statement as follows
 *  double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
 *
 * The number of values between braces { } cannot be larger than the number of elements that we declare for the array between square brackets [ ].
 * 
 * If you omit the size of the array, an array just big enough to hold the initialization is created. Therefore, if you write 
 *      double balance[] = {1000.0, 2.0, 3.4, 17.0, 50.0};
 *          You will create exactly the same array as you did in the previous example.
 *      balance[4] = 50.0;
 *          The above statement assigns element number 5th in the array a value of 50.0. Array with 4th index will be 5th, i.e., last element because all arrays have 0 as the index of their first element which is also called base index.
 *          Following is the pictorial representation of the same array we discussed above
 *                       0       1       2       3       4
 *          balance    1000.0   2.0     3.4     7.0     50.0
 * 
 * Accessing array elements
 * 
 * An element is accessed by indexing the array name.
 * This is done by placing the index of the element within square brackets after the name of the array
*/

#include<iostream>

using namespace std;

int main(void)
{
    int drawer [5] = { 2, 4, 6, 8, 10 };
    cout << drawer[0];
}

/*
 *  Output:
 *  2
 */
