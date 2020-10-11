// IF ELSE STATEMENT

/*
    *An if statemnt can be followed bu an optional else statement which
     executes when the boolean expression is false.

    *If the boolean expression evaluates to true, then the if block of code will be executed, 
    otherwise else block of code will be executed.

    if ( boolean_expression )
    {

    }
    else
    {

    }

*/

#include<iostream>

using namespace std;

int main (void)
{
    int num = 100;

    if ( num < 20)
    {
        cout << " num is less than 20 " << endl;
    }
    else
    {
        cout << " num is more than 20" << endl;
    }

    cout << "The value of num is: " << num << endl;

    
}

/*
    Output:
     num is more than 20
    The value of num is: 100
*/