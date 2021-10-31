// Responsible for input and output
#include <iostream>

// Responsible for other string libraries
#include<string.h>

using namespace std;

// Group of data elements grouped together under one name
struct student
{
    char name[99];
    int age;
} students, tempStudent;

// Function declaration
void display(int item, student students[]);
void swaps(student &obj1, student &obj2);
void bubbleSort(int item, student students[]);
void insertionSort(int item, student students[]);
//void mergeSort(student students[], int low, int high);
//void merge(student students[], int low, int mid, int high);

int main()
{
    /*********************************************
     * items handles how many items.             *
     * option handles the type of algo to choose *
     * index for indexing                        *
     *********************************************/
    int items, option, index, low = 0, high = 0;

    // Prompts the user to enter how many elements.
    cout << "Enter the number of students you would like to input? ";
    cin >> items;

    /*********************
     * student data type *
     * students students    *
     *********************/
    students[items];// Set the students based on how many items they entered

    cout << "Please state your name and age of the stundents\n";

    /*********************************************************************
     * In initialize expression index is set to 0 by default             *
     * The test expression will be if index is < 0 to the value of items *
     * items is the value that handles how many items -line 26.          *
     * Lastly is increment i++, stops until i and num is both equal.     *
     *********************************************************************/

    // Getting the names
    for (index = 0; index < items; index++)
    {
        cout << "Name: ";
        cin >> students[index].name;
    }

    // Getting the age with their names indicated
    for (index = 0; index < items; index++)
    {
        cout << students[index].name << "'s age: ";
        cin >> students[index].age;
    }

    // For Merge Sort
    auto arr_size = sizeof(students) / sizeof(students[0]);
    //display(items, students);

    /************************************************************************
     * Ask the user what type of sorting algorithm they want to use to sort *
     * the age of the students from ascending order.                         *
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
        insertionSort(items, students, tempStudent);
        break;
    case 3:
        cout << "Algorithm: Merge sort\n\nBefore Sorting: \n";
        display(items, students);
        printf("\nAfter Sorting: \n");
        mergeSort(students, 0, arr_size - 1);
        display(arr_size, students);
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
    for (auto index = 0; index < item; index++)
    {
        cout << students[index].age << " " << students[index].name << "\n";
    }
}

/***************
 * BUBBLE SORT *
 ***************/
void swaps(student &obj1, student &obj2)
{
    student temp;
    temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

void bubbleSort(int item, student students[])
{   
    /***
     *  
     */
    for (int index = 0; index < item - 1; index++)
    {
        int flag = 0;
        for (int studentIndex = 0; studentIndex < item - index - 1; studentIndex++)
        {
            if (students[studentIndex].age > students[studentIndex + 1].age)
            {
                swaps(students[studentIndex], students[studentIndex + 1]);
                flag = 1;
            }
            if (!flag)
                break;
        }
    }
    display(item, students);
}

/******************
 * INSERTION SORT *
 ******************/
void insertionSort(int item, student students[])
{
    int index, key, prev;

    // index is the step to the loop
    for (index = 1; index < item; index++)
    {
        // Gets the 2nd element and stores it separately in key
        key = students[index].age;

        // The previous index
        prev = index - 1;

        /**************************************************** 
         * Move elements of arrarys[0..i-1], that are       *
         * greater than key, to one position ahead of their * 
         * current position                                 *
         ****************************************************/
        while (prev >= 0 && students[prev].age > key)
        {
            //students[prev + 1].age = students[prev].age;
            swaps(students[prev + 1], students[prev]);
            key = students[prev].age;
            prev--;
        }
        /*************************************************************** 
         * After the while loop, all the greater items have been       *
         * shifted to the right, finally we can store the current item *
         * at index j + 1 equals current                               *
         ***************************************************************/
        students[prev + 1].age = key;
    }
    display(item, students);
}

/**************
 * MERGE SORT *
 **************/
// begin is for left index and end is
// right index of the sub-students
// of arr to be sorted */
// void mergeSort(student students[], int const begin, int const end)
// {
// 	if (begin >= end)
// 		return; // Returns recursivly

// 	auto mid = begin + (end - begin) / 2;
// 	mergeSort(students, begin, mid);
// 	mergeSort(students, mid + 1, end);
// 	merge(students, begin, mid, end);
// }

// // Merges two subarrays of students[].
// // First subarray is arr[begin..mid]
// // Second subarray is arr[mid+1..end]
// void merge(student students[], int const left, int const mid, int const right)
// {
// 	auto const subArrayOne = mid - left + 1;
// 	auto const subArrayTwo = right - mid;

// 	// Create temp arrays
// 	auto *leftArray = new int[subArrayOne],
// 		 *rightArray = new int[subArrayTwo];

// 	// Copy data to temp arrays leftArray[] and rightArray[]
// 	for (auto i = 0; i < subArrayOne; i++)
// 		leftArray[i] = students[left + i].age;
// 	for (auto j = 0; j < subArrayTwo; j++)
// 		rightArray[j] = students[mid + 1 + j].age;

// 	auto indexOfSubArrayOne = 0,   // Initial index of first sub-students
// 		indexOfSubArrayTwo = 0;	   // Initial index of second sub-students
// 	int indexOfMergedArray = left; // Initial index of merged students

// 	// Merge the temp arrays back into students[left..right]
// 	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
// 	{
// 		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
// 		{
// 			students[indexOfMergedArray].age = leftArray[indexOfSubArrayOne];
// 			indexOfSubArrayOne++;
// 		}
// 		else
// 		{
// 			students[indexOfMergedArray].age = rightArray[indexOfSubArrayTwo];
// 			indexOfSubArrayTwo++;
// 		}
// 		indexOfMergedArray++;
// 	}
// 	// Copy the remaining elements of
// 	// left[], if there are any
// 	while (indexOfSubArrayOne < subArrayOne)
// 	{
// 		students[indexOfMergedArray].age = leftArray[indexOfSubArrayOne];
// 		indexOfSubArrayOne++;
// 		indexOfMergedArray++;
// 	}
// 	// Copy the remaining elements of
// 	// right[], if there are any
// 	while (indexOfSubArrayTwo < subArrayTwo)
// 	{
// 		students[indexOfMergedArray].age = rightArray[indexOfSubArrayTwo];
// 		indexOfSubArrayTwo++;
// 		indexOfMergedArray++;
// 	}
// }

// End