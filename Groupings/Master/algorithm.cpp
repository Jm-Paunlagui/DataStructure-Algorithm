/**
 * 3 CS1
 * @Author 
 *      Bueno, Nathanael
 *      Hinggan, Mutya
 *      Paunlagui, John Moises
 *      Tolentino, Charles Justine
 */
#include <iostream>

// Responsible for other string libraries
#include <string.h>

#include <iomanip>


using namespace std;

// Group of data elements grouped together under one name
struct student
{
    string name;
    int age;
} students,
    tempStudentBubbleSort,
    currentStudentInsertionSort,
    tempStudentMergeSort;

// Function declaration
void display(int item, student students[]);
void bubbleSort(int item, student students[]);
void insertionSort(int item, student students[]);
void mergeSort(student students[], int const begin, int const end, int item);
void merge(student students[], int const begin, int const mid, int const end, int item);

// Driver Code
int main()
{

    /*********************************************
     * items handles how many items.             *
     * option handles the type of algo to choose *
     * index for indexing                        *
     *********************************************/
    int items, index, option;

    char again;

    // Prompts the user to enter how many elements.
    cout << "Enter the number of students you would like to input? ";
    cin >> items;
    student students[items];

    // Getting the names
    cout << "\nPlease state the name of the students\n";

    for (index = 0; index < items; index++)
    {
        cout << "[" << index + 1 << "] Name: ";
        cin >> students[index].name;
    }

    // Getting the Age with their names indicated
    cout << "\nPlease state the age of the students\n";

    for (index = 0; index < items; index++)
    {
        cout << "[" << index + 1 << "] " << students[index].name << "'s age is: ";
        cin >> students[index].age;
    }

    // For Merge Sort
    auto arr_size = sizeof(students) / sizeof(students[0]);

    /************************************************************************
     * Ask the user what type of sorting algorithm they want to use to sort *
     * the age of the students from ascending order.                        *
     ************************************************************************/
    do
    {
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
            mergeSort(students, 0, arr_size - 1, items);
            display(arr_size, students);
            break;
        default:
            cout << "Invalid Selection!";
            break;
        }

        //Prompts user to repeat
        cout << "Do you want to try other sorting algorithm [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
    cout << "Done.";
}

/****************************************
 * TO DISPLAY UNSORTED AND SORTED ARRAY *
 ****************************************/
void display(int item, student students[])
{
    cout << "\nNo.\t\tAge\t\tName\n";
    for (auto index = 0; index < item; index++)
    {
        cout << "[" << index + 1 << "]\t\t" << students[index].age << "\t\t" << students[index].name << endl;
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
    for (index = 1; index < item; index++)
    {
        // Gets the 2nd element and stores it separately in temp
        currentStudentInsertionSort = students[index];

        // Previous index
        prevStudentIndex = index - 1;

        /*
         * Move elements of arrarys[0..i-1], that are       
         * greater than key, to one position ahead of their
         * current position                                 
         */
        while (prevStudentIndex >= 0 && students[prevStudentIndex].age > currentStudentInsertionSort.age)
        {
            students[prevStudentIndex + 1] = students[prevStudentIndex];

            // Then decrement
            prevStudentIndex--;
        }

        /* 
         * After the while loop, all the greater items have been       
         * shifted to the right, finally we can store the current item 
         * at index j + 1 equals current                               
         */
        students[prevStudentIndex + 1] = currentStudentInsertionSort;
    }

    display(item, students);

}

/**************
 * MERGE SORT *
 **************/
// Merges two subarrays of students[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(student students[], int const begin, int const mid, int const end, int item)
{
    
    int left_index = begin;
    int right_index = mid + 1;
    int combined_index = begin;
    student tempStudentMergeSort[item];

    while (left_index <= mid && right_index <= end)
    {
        if (students[left_index].age <= students[right_index].age)
        {
            tempStudentMergeSort[combined_index++] = students[left_index++];
        }
        else
        {
            tempStudentMergeSort[combined_index++] = students[right_index++];
        }
    }

    if (left_index == mid + 1)
    {
        while (right_index <= end)
        {
            tempStudentMergeSort[combined_index++] = students[right_index++];
        }
    }
    else
    {
        while (left_index <= mid)
        {
            tempStudentMergeSort[combined_index++] = students[left_index++];
        }
    }

    for (int index = begin; index <= end; index++)
    {
        students[index] = tempStudentMergeSort[index];
    }
}

void mergeSort(student students[], int const begin, int const end, int item)
{

    if (begin >= end)
        return; // Returns recursivly

    auto mid = (begin + end) / 2;
    mergeSort(students, begin, mid, item);
    mergeSort(students, mid + 1, end, item);
    merge(students, begin, mid, end, item);
}
