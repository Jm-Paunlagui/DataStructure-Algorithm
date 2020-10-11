// CONTINUE

/*
    continue;

    *Cause the loop to skip yhe remainder of its body and immediately retest 
    its condition prior to reiterating

    *The continue statement works somewhat like the break statement. 
     Instead of forcing termination, however, continue forces the next iteration of the loop to take place,
     skipping any code in between.

    *For the for loop, continue causes the conditional test and increment portions of the loop to execute.
     For the while and do...while loops, program control passes to the conditional tests.
*/

#include<iostream>

using namespace std;

int main (void)
{
    int num = 10;

    do
    {
        if ( num == 15 )
        {
            num++;
            continue;
        }
        cout << "Value of a: " << num << endl;
        num++;
        
    } while ( num < 20);
    
}

/*
    Output:
    Value of a: 10
    Value of a: 11
    Value of a: 12
    Value of a: 13
    Value of a: 14
    Value of a: 16
    Value of a: 17
    Value of a: 18
    Value of a: 19
*/