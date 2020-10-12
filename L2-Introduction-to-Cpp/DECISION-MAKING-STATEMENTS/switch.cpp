// SWITCH STATEMENTS

/*
 *
 *    switch (expression)
 *    {
 *    case  constant-expression :
 *         code 
 *        break;
 *    
 *    default:
 *        break;
 *    }
 * A switch statement allows a variable to be tested for equally against a list fo values
 *
 * Allows a variable to be tested for equality against a list of values. 
 * Each value is called a case, and the variable being switched on is checked for each case.
 *
 * The following rules apply to a switch statement:
 *
 * ~ The expression used in a switch statement must have an integral or enumerated type, 
 *   or be of a class type in which the class has a single conversion function to an integral or enumerated type.
 *
 * ~ You can have any number of case statements within a switch. 
 *   Each case is followed by the value to be compared to and a colon.
 *
 * ~ The constant-expression for a case must be the same data type as the variable in the switch, 
 *   and it must be a constant or a literal.
 *
 * ~ When the variable being switched on is equal to a case, 
 *   the statements following that case will execute until a break statement is reached.
 *
 * ~ When a break statement is reached, the switch terminates, 
 *   and the flow of control jumps to the next line following the switch statement.
 *
 * ~ Not every case needs to contain a break. If no break appears, 
 *   the flow of control will fall through to subsequent cases until a break is reached.
 *
 * ~ A switch statement can have an optional default case, 
 *   which must appear at the end of the switch. 
 *   The default case can be used for performing a task when none of the cases is true. 
 *   No break is needed in the default case.
*/

#include <iostream>

using namespace std;

int main (void)
{
    char grade = 'D';
    switch (grade)
    {
    case 'A':
        cout << "Outstanding" << endl;
        break;
    case 'B':
        cout << "Excellent" << endl;
        break;
    case 'C':
        cout << "Well done" << endl;
        break;
    case 'D':
        cout << "Fair" << endl;
        break;
    case 'F':
        cout << "Failed" << endl;
        break;
    
    default: cout << "Invalid" << endl;
        break;
    }

    cout << "Your grade is " << grade << endl;
}

/*
 *  Output
 *  Fair
 *  Your grade is D
*/