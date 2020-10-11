// RANDOM NUMBERS

/*
    There are many cases where you will wish to generate a random number.
     There are actually two functions you will need to know about random number generation.
     The first is rand(), this function will only return a pseudo random number.
     The way to fix this is to first call the srand() function

    Following is a simple example to generate few random numbers.
     This example makes use of time() function to get the number of seconds on your system time,
     to randomly seed the rand() function –
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    int index, randNum;
    // set the seed
    srand ( ( unsigned ) time ( NULL ) );
    
    // to generate 10 random numbers
    for (index = 0; index < 10; index++)
    {
        // generate actual random number
        randNum = rand();
        cout << "Random Numbers: " << randNum << endl;
    }
    return 0;
} 