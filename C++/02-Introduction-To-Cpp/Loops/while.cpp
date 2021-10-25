// WHILE LOOP

/*
 *
 *   while ( condition )
 *   {
 *       statement(s);
 *   }
 *   
 *   Repeats a statement or group of statement while a given condition is true.
 *   It test the condition before executing the loop body.
*/

#include<iostream>

using namespace std;

int main (void)
{
    int num = 10;

    while (num < 20)
    {
        cout << "Value of a: " << num << endl;
        num++;
    }
    
}

/*
 *   Output:
 *   Value of a: 10
 *   Value of a: 11
 *   Value of a: 12
 *   Value of a: 13
 *   Value of a: 14
 *   Value of a: 15
 *   Value of a: 16
 *   Value of a: 17
 *   Value of a: 18
 *   Value of a: 19
*/