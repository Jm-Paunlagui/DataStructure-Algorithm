// GOTO

/*

    goto label;
    ..
    .
    label: statement;
    *Where label is an identifier that identifies a labeled statement.
     A labeled statement is any statement that is preceded by an identifier followed 
     by a colon (:)
    
    *Transfes control to the labeled statement. Though it is not advised to use
     goto statement in your program.


    Note: One good use of goto is to exit from a deeply nested routine.
    for (...)
    {
        for (...)
        {
            while(...)
            {
                if (...) goto stop;
                .
                .
                .
            }
        } 
    }
    stop: cout << "Runtime Error. \n";
*/

#include <iostream>

using namespace std;

int main (void)
{
    int num = 10;

    LOOP: do
    {
        if ( num == 15 )
        {
            num++;
            goto LOOP;
        }
        cout << "Value of a: " << num << endl;
        num++;
        
    } while ( num < 20 );
    
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