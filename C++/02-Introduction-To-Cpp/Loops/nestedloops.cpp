// NESTED LOOPS

/*
You can use one or more loop inside any another while, for or do..while loop.
*/

/*
 *   for ( init ; condition; ++ or --)
 *   {
 *       for (init ; condition; ++ or --)
 *      {
 *           statement(s);
 *      }
 *      statement(s);
 *  }
 *
 *  The syntax for a nested while loop statement
 *  while ( condition )
 *  {
 *      while ( condition )
 *      {
 *          statement(s);
 *      }
 *      statement(s);
 *  }
 *
 *  The syntax for a nested do..while loop statement
 *  do
 *  {
 *      statement(s);
 *      do
 *      {
 *           statement(s);
 *      } while ( condition );
 *       
 *   } while ( condition );
*/

#include<iostream>

using namespace std;

int main ()
{
    int i, j;

    for ( i = 2; i < 100; i++ )
    {
        for ( j = 2; j <= ( i / j ) ; j++ )
            if (!(i % j)) break;
            if (j > (i / j))
                cout << i << " is prime" << endl;
    }
    return 0;

}

/*
 *  Output:
 *  2 is prime
 *  3 is prime
 *  5 is prime
 *  7 is prime
 *  11 is prime
 *  13 is prime
 *  17 is prime
 *  19 is prime
 *  23 is prime
 *  29 is prime
 *  31 is prime
 *  37 is prime
 *  41 is prime
 *  43 is prime
 *  47 is prime
 *  53 is prime
 *  59 is prime
 *  61 is prime
 *  67 is prime
 *  71 is prime
 *  73 is prime
 *  79 is prime
 *  83 is prime
 *  89 is prime
 *  97 is prime
*/