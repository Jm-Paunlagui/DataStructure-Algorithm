#include <iostream>
#include <iomanip>

using namespace std;
using std::setw;

int main (void)
{
    int num [ 10 ]; // num is an array of 10 integes

    // initialize elements of array num to 0
    for (int i = 0; i < 10; i++)
    {
        num [ i ] = i + 100;
    }
    cout << "* Element" << setw( 13 ) << "Value" << endl;

    // Output each array element's value
    for (int j = 0; j < 10; j++)
    {
        cout << setw( 7 ) << j << setw ( 13 ) << num[j] << endl;
    }
    
}

/*
 *  Output:
 * Element        Value
 *      0          100
 *      1          101
 *      2          102
 *      3          103
 *      4          104
 *      5          105
 *      6          106
 *      7          107
 *      8          108
 *      9          109
*/
