// Responsible for input and output
#include <iostream>

// Responsible for other string libraries
#include <string.h>

using namespace std;

// Group of data elements grouped together under one name
struct student
{
    string name;
    int age;
} students, tempStudentBubbleSort, currentStudentInsertionSort;

// Function declaration
void display(int item, student students[]);
void bubbleSort(int item, student students[]);
void insertionSort(int item, student students[]);

// Driver Code
int main()
{

    /*********************************************
     * items handles how many items.             *
     * option handles the type of algo to choose *
     * index for indexing                        *
     *********************************************/
    int items, index, option;

    // Prompts the user to enter how many elements.
    cout << "Enter the number of students you would like to input? ";
    cin >> items;
    student students[items];

    // Getting the names
    cout << "Please state the name of the students\n";

    for (index = 0; index < items; index++)
    {
        cout << "[" << index + 1 << "] Name: ";
        cin >> students[index].name;
    }

    // Getting the Age with their names indicated
    cout << "Please state the age of the students\n";

    for (index = 0; index < items; index++)
    {
        cout << students[index].name << "'s age is: ";
        cin >> students[index].age;
    }

    /************************************************************************
     * Ask the user what type of sorting algorithm they want to use to sort *
     * the age of the students from ascending order.                        *
     ************************************************************************/
    cout << "\nWhat sorting algorithm do you want to use??\n1 for Bubble sort\n2 for Insertion sort\n3 for Merge sort\n";
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Algorithm: Bubble sort\n\nBefore Sorting: \n";
        display(items, students);
        printf("\nAfter Sorting: \n");
        bubbleSort(items, students);
        break;
    case 2:
        cout << "Algorithm: Insertion sort\n\nBefore Sorting: \n";
        display(items, students);
        printf("\nAfter Sorting: \n");
        insertionSort(items, students);
        break;
    case 3:
        cout << "Algorithm: Merge sort\n\nBefore Sorting: \n";
        display(items, students);
        printf("\nAfter Sorting: \n");

        break;
    default:
        cout << "Invalid Selection!";
        break;
    }
}

/****************************************
 * TO DISPLAY UNSORTED AND SORTED ARRAY *
 ****************************************/
void display(int item, student students[])
{
    cout << "\nNo.   Age  Name\n";
    for (auto index = 0; index < item; index++)
    {
        cout << "[" << index + 1 << "]   " <<students[index].age << "   " << students[index].name << "\n";
    }
}

/***************
 * BUBBLE SORT *
 ***************/
void bubbleSort(int item, student students[])
{
    int index, studentIndex;

    for (index = 0; index < item - 1; index++)
    {
        for (studentIndex = 0; studentIndex < item - index - 1; studentIndex++)
        {
            if (students[studentIndex].age > students[studentIndex + 1].age)
            {
                // Sets temp to students
                tempStudentBubbleSort = students[studentIndex];

                // students is now the value of students + 1
                students[studentIndex] = students[studentIndex + 1];

                // students + 1 will get the value of the temp
                students[studentIndex + 1] = tempStudentBubbleSort;
            }
        }
    }
    display(item, students);
}

/******************
 * INSERTION SORT *
 ******************/
void insertionSort(int item, student students[])
{
    int index, prevStudentIndex;

    // index is the step to the loop
    for (index = 1; index < item; index++){
        // Gets the 2nd element and stores it separately in temp
        currentStudentInsertionSort = students[index];

        // Previous index
        prevStudentIndex = index - 1;

        /**************************************************** 
         * Move elements of arrarys[0..i-1], that are       *
         * greater than key, to one position ahead of their * 
         * current position                                 *
         ****************************************************/
        while (prevStudentIndex >= 0 && students[prevStudentIndex].age > currentStudentInsertionSort.age)
        {
            students[prevStudentIndex + 1] = students[prevStudentIndex];

            // Then decrement
            prevStudentIndex--;
        }

        /*************************************************************** 
         * After the while loop, all the greater items have been       *
         * shifted to the right, finally we can store the current item *
         * at index j + 1 equals current                               *
         ***************************************************************/
        students[prevStudentIndex + 1] = currentStudentInsertionSort;
        
    }

    display(item, students);
}

/**************
 * MERGE SORT *
 **************/