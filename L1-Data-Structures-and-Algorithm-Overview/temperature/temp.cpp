#include<iostream>

using namespace std;

int main(void)
{
    int celsius; 
    double fahrenheit; 
    cout<< "Input temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = ( 9.0 / 5.0 * celsius ) + 32;
    cout << fahrenheit << " F";
}