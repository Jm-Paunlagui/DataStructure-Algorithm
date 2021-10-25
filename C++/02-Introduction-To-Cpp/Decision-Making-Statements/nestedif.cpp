// NESTED IF STATEMENT

/*
 * You can use one if or else statement inside another if or else if statements
 *
 * It is always legal to nest if-else statements,
 * which means you can use one if or else if statement inside another if or else if statement(s).
 *
 *  if ( condition )
 *   {
 *      if ( condition )
 *       {
 *            code 
 *       }
 *       
 *  }
*/

#include <iostream>

using namespace std;

int main (void)
{
    int num1 = 100, num2 = 200;

    if ( num1 == 100 )
    {
        if ( num2 == 200 )
        {
            cout << "Value of num1 is: " << num1 << " and num2 is: " << num2 << endl;
        }
        
    }

    cout << "Exact Value of num1 is: " << num1 << endl;
    cout << "Exact Value of num2 is: " << num2 << endl;
    
} 

/*
 *  Output:
 *  Value of num1 is: 100 and num2 is: 200
 *   Exact Value of num1 is: 100
 *  Exact Value of num1 is: 200
*/