// DO WHILE

/*

    do
    {
        statement(s);
    } while ( condition );

 *Unlike for and while loops, which test the loop condition at the top of the loop, 
  the do...while loop checks its condition at the bottom of the loop.

 *A do...while loop is similar to a while loop, except that a 
  do...while loop is guaranteed to execute at least one time.

 *Notice that the conditional expression appears at the end of the loop, 
 so the statement(s) in the loop execute once before the condition is tested.

 *If the condition is true, the flow of control jumps back up to do, 
  and the statement(s) in the loop execute again. This process repeats until the given condition becomes false.
*/

/*
Like a while statement, except that it tests the condition at the end
of the loop body.
*/

#include<iostream>

using namespace std;

int main (void)
{
    int num = 10;
    do
    {
        cout << "Value of a: " << num << endl;
        num++;
    } while (num < 20);

}

/*
    Output:
    Value of a: 10
    Value of a: 11
    Value of a: 12
    Value of a: 13
    Value of a: 14
    Value of a: 15
    Value of a: 16
    Value of a: 17
    Value of a: 18
    Value of a: 19
*/