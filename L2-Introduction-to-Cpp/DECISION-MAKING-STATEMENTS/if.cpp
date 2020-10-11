// IF STATEMENT

/*
    if ( boolean_expression )
    {
        // statement(s) will execute fi the boolean expression is true
    }

    *If statement consists of a boolean expression followed by on or more 
     statements.

    *If the boolean expression evaluates to true, 
     then the block of code inside the if statement will be executed. 

    *If boolean expression evaluates to false, 
     then the first set of code after the end of the if statement (after the closing curly brace) will be executed.
*/

#include <iostream>

using namespace std;

int main (void)
{
    int num = 10;

    
    if ( num < 20)
    {
        cout << "num is less than 20" << endl;
    }
    cout << "value of num is: " << num << endl;

}

/*
    Output:
    num is less than 20
    value of num is: 10
*/