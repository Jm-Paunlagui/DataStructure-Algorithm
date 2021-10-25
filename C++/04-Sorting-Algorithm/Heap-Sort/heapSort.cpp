/**
 * Heap sort is a comparison based sorting technique based on Binary Heap data structure. 
 * It is similar to selection sort where we first find the maximum element and place the 
 * maximum element at the end. We repeat the same process for remaining element. 
 * 
 * A Binary Heap is a Complete Binary Tree where items are stored in a special order such
 * that value in a parent node is greater(or smaller) than the values in its two children nodes. 
 * The former is called as max heap and the latter is called min heap. The heap can be represented 
 * by binary tree or array.
*/

#include <iostream>

using namespace std;

// Funtion declaration
void heapify(int arr[], int num, int index);
void heapSort(int arr[], int num);
void display(int arr[], int size);

int main(void)
{
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int arr[num];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "Arrays before sorting: ";
    display(arr, num);
    heapSort(arr, num);
    cout << "Arrays after sorting: ";
    display(arr, num);
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int num, int index)
{
    int largest = index; // Initialize largest as root
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // if left child is larger than root
    if (left < num && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < num && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != index)
    {
        swap(arr[index], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, num, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int num)
{
    // Build heap (rearrange array)
    for (int i = num / 2 - 1; i >= 0; i--)
        heapify(arr, num, i);

    for (int i = num - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void display(int arr[], int size)
{
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}
