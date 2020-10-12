// BREAK

/*
 * break;
 *
 *  Terminates the loop or switch statement and transfers the execution to the statement
 *  immediately following the loop or switch
*/

#include<iostream>

using namespace std;

int main(void)
{
    int num = 10;

    do
    {
        cout << "Value of a: " << num << endl;
        num++;
        if (num > 15)
        {
            break;
        }
        
    } while (num < 20);
    
}


/*
 *  Output:
 *  Value of a: 10
 *  Value of a: 11
 *  Value of a: 12
 *  Value of a: 13
 *  Value of a: 14
 *  Value of a: 15
*/

