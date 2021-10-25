#include<iostream>

using namespace std;

int main(void)
{
    int num1, num2, num3;
    cout << "Three numbers to compare\n";
    cin >> num1 >> num2 >> num3;

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            cout << num1 << " is the largest" << endl;
        }
        else
        {
            cout << num3 << " is the largest " << endl;
        }
        
    }
    if ( num2 > num3) 
    {
        cout << num2 << " is the largest" << endl;
    }
    else
    {
        cout << num3 << " is the largest" << endl;
    }
    
}