// CHARACTERS AND STRINGS

/**
 * 
 * Plain arrays with null-terminated sequences of characters are the typical types used in the C language to represent strings (that is why they are also known as C-strings). 
 * In C++, even though the standard library defines a specific type for strings (class string), still, plain arrays with null-terminated sequences of characters (C-strings) 
 * are a natural way of representing strings in the language; in fact, string literals still always produce null-terminated character sequences, and not string objects.
 * 
 */

#include <iostream>
#include<string>

using namespace std;

int main (void)
{
    char question1[] = { " * What's your name? " };
    string question2 = { " * Where do you live? "};

    char answer1[80];
    string answer2;

    cout << question1;
    cin >> answer1;

    cout << question2;
    cin >> answer2;

    cout << " * Hello, " << answer1 << " from " << answer2 << endl;
}

/**
 * Output:
 * What's your name? <answer1>
 * Where do you live? <answer2>
 * Hello, <answer1> from <answer2>
 * 
 */