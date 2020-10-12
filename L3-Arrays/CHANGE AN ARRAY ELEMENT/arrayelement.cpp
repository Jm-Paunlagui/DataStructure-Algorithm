/**
 * To change the value of a specific element, refer to the index number:
 * 
 * Example
 * 
 * cars[0] = "Opel";
 * 
 */ 

#include<iostream>
#include<string>

using namespace std;

int main (void)
{
    string cars[4] = { "Volvo", "BMW", "Ford", "Mazda" };

    cars[0] = "Opel";
    cout << cars[0];
}

/**
 * Output:
 * Opel
 */ 