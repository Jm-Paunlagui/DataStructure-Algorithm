// QUICK SORT ALGORITHM
/**
 * Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. 
 * A large array is partitioned into two arrays one of which holds values smaller than the specified value, say pivot, 
 * based on which the partition is made and another array holds values greater than the pivot value.
 * 
 *
 * Quicksort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. 
 * This algorithm is quite efficient for large-sized data sets as its average and worst-case complexity are O(nLogn) and O(n2), respectively.
 * 
 * QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. 
 * There are many different versions of quickSort that pick pivot in different ways.
 * 
 * QUICK SORT PIVOT ALGORITHM Based on our understanding of partitioning in quick sort, 
 * we will now try to write an algorithm for it, which is as follows
 * 
 *  Step 1 - Choose the highest index value has pivot
 *  Step 2 - Take two variables to point left and right of the excluding pivot
 *  Step 3 - Left points to the low index
 *  Step 4 - Right points to the high
 *  Step 5 - While value at the left is less than the pivot, move right
 *  Step 6 - While value at right is greater than pivot move left
 *  Step 7 if both step 5 and step 6 does not match swap left and right
 *  Step 9 if left >= right, the point where they met is new pivot
 * 
 * Using pivot algorithm recursively, we end up with smaller possible partitions. Each partition is then processed for quick sort. 
 * We define recursive algorithm for quicksort as follows
 * 
 *  Step 1 - Make the right-most index value pivot
 *  Step 2 - Partition the array using pivot value
 *  Step 3 - quickSort left partition recursively
 *  Step 4 - quickSort right partition recursively
*/

#include <bits/stdc++.h>

using namespace std;
// Function declaration
void swap (int* num1, int* num2);
int partition (int arr[], int low, int high);
void quickSort (int arr[], int low, int high);
void display (int arr[], int size);

int main (void)
{
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int arrays[num];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arrays[i];
    }
    cout << "Arrays before sorting: ";
    display( arrays, num);
    quickSort ( arrays, 0, num - 1);
    cout << "Arrays after sorting: ";
    display ( arrays, num);    
}

// A function to swap two elements
void swap (int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/**
 *  This function takes last element as pivot, places the pivot element at its correct 
 *  position in sorted array, and places all smaller (smaller than pivot) to left of pivot
 *  and all greater elements to right of pivot
 */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int index = (low -1);

    for (int j = low; j <= high - 1; j++)
    {
        // if the current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            index++; // increment index of smaller element
            swap(&arr[index], &arr[j]);
        }
        
    }
    swap(&arr[index + 1], &arr[high]);
    return ( index + 1);
    
}

/**
 *  arr[] --> array to be sorted
 * low -->  Starting index
 * high --> Ending index
 */

void quickSort (int arr[], int low, int high)
{
    if (low < high)
    {
        /**
         * pi is partitioning index, arr[p] is now at the right
         * place
        */
       int pi = partition(arr, low, high);

       /**
        * Separately sort elements before
        * partition and after partition 
        */
       quickSort(arr, low, pi - 1);
       quickSort(arr, pi + 1, high);
    }
    
}

void display (int arr[], int size)
{
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;  
}
