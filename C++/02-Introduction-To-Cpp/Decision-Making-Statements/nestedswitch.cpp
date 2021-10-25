// NESTED SWITCH STATEMENTS

/*
 * You can use one switch statement inside of another switch statements
 *
 * It is possible to have a switch as part of the statement sequence of an outer switch.
 * Even if the case constants of the inner and outer switch contain common values, 
 * no conflicts will arise.
*/

#include <iostream>

using namespace std;

int main (void)
{
    int num1 = 100, num2 = 200;

    switch (num1)
    {
    case 100:
        cout << "This is the outer part" << endl;
        
        switch (num2)
        {
        case 200:
            cout << "This is the inner part" << endl;
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }

    cout << "Exact Value of num1 is: " << num1 << endl;
    cout << "Exact Value of num2 is: " << num2 << endl;
    
} 

/*
 *  Output
 *  This is the outer part
 *  This is the inner part
 *  Exact Value of num1 is: 100
 *  Exact Value of num2 is: 200
*/