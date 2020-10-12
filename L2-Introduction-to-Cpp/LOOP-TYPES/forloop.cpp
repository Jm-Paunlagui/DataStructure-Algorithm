// FOR LOOP

/*
 *
 *  for ( init ; condition; ++ or --)
 *   {
 *       statement(s);
 *   }
 * Here is the flow of control in a for loop 
 *
 *  The init step is executed first, and only once. 
 *  This step allows you to declare and initialize any loop control variables. 
 *  You are not required to put a statement here, as long as a semicolon appears.
 *
 *  Next, the condition is evaluated. If it is true, the body of the loop is executed. 
 *  If it is false, the body of the loop does not execute and flow of control jumps to the next statement just after the for loop.
 *
 *  After the body of the for loop executes, the flow of control jumps back up to the increment statement.
 *  This statement can be left blank, as long as a semicolon appears after the condition.
 *
 *  The condition is now evaluated again. If it is true, the loop executes and the process repeats 
 *  itself (body of loop, then increment step, and then again condition). After the condition becomes false, 
 *  the for loop terminates.
 *
 * Execute a sequence of statement multiple times and abbreviates the code that
 * manages the loop variable.
*/

#include<iostream>

using namespace std;

int main (void)
{
    for (int i = 10; i < 20; i++)
    {
         cout << "Value of a: " << i << endl;
    }
    
}

/*
 *   Output:
 *   Value of a: 10
 *   Value of a: 11
 *   Value of a: 12
 *  Value of a: 13
 *  Value of a: 14
 *   Value of a: 15
 *   Value of a: 16
 *   Value of a: 17
 *   Value of a: 18
 *  Value of a: 19
*/
