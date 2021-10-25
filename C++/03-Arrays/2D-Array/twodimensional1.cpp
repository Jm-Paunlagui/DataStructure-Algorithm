#include<iostream>

using namespace std;

int main (void)
{
    int marks [2][5] =
    {
        { 2, 4, 6, 8, 10},
        { 1, 3, 5, 7, 9}
    };

    cout<< marks[0][3] << "\t" << marks[1][4];
}

/*
 * Output
 * 8      9
 */