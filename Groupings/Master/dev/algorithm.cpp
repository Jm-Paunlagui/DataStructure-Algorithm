#include <iostream>

using namespace std;

class student
{
private:
    string name;
    int age;

public:
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

// Function declaration
void display(student students[], int item);
void bubbleSort(student students[], int item);
void insertionSort(student students[], int item);
void merge(student array[], int const left, int const mid, int const right);
void mergeSort(student array[], int const begin, int const end);

int main()
{
    int items, index, option, age;
    string name;
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
        cin >> name;
        students[index].setName(name);
    }

    // Getting the Age with their names indicated
    cout << "\nPlease state the age of the students\n";

    for (index = 0; index < items; index++)
    {
        cout << "[" << index + 1 << "] " << students[index].getName() << "'s age is: ";
        cin >> age;
        students[index].setAge(age);
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
            display(students, items);
            printf("\nAfter Sorting: \n");
            bubbleSort( students, items);
            break;
        case 2:
            cout << "Algorithm: Insertion sort\n\nBefore Sorting: \n";
            display(students, items);
            printf("\nAfter Sorting: \n");
            insertionSort(students, items);
            break;
        case 3:
            cout << "Algorithm: Merge sort\n\nBefore Sorting: \n";
            display(students, items);
            printf("\nAfter Sorting: \n");
            mergeSort(students, 0, arr_size - 1);
            display(students, arr_size);
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
void display(student students[], int item)
{
    cout << "\nNo.\t\tAge\t\tName\n";
    for (auto index = 0; index < item; index++)
    {
        cout << "[" << index + 1 << "]\t\t" << students[index].getAge() << "\t\t" << students[index].getName() << endl;
    }
}

// A function to implement bubble sort
void bubbleSort(student students[], int item)
{
    int i, j;
    student temp;
    for (i = 0; i < item - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < item - i - 1; j++)
            if (students[j].getAge() > students[j + 1].getAge()){
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }

    display( students,item);            
}

/* Function to sort an array using insertion sort*/
void insertionSort(student students[], int item)
{
    int i, j;
    student key;
    for (i = 1; i < item; i++)
    {
        key = students[i];
        j = i - 1;

        /* Move elements of students[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && students[j].getAge() > key.getAge())
        {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
    display(students, item);
}

void merge(student array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    student leftArray[subArrayOne],
        rightArray[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne].getAge() <= rightArray[indexOfSubArrayTwo].getAge())
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of students to be sorted */
void mergeSort(student array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
// end