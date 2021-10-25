#include <iostream>

using namespace std;

int main (void)
{
    int num1 [4] = { 1, 2, 3, 4};
    int num2 [4] = { 2, 3, 4, 4};

    int sum, diff, product, quotient;

    sum = num1[0] + num2[0];
    diff = num1[1] - num2[1];
    product = num1[2] * num2[2];
    quotient= num1[3] / num2[3];

    cout << sum << endl;
    cout << diff << endl;
    cout << product << endl;
    cout << quotient << endl;
}

/*
 * Output:
 * 3
 * -1
 * 12
 * 1
 *  
 */
