// C++ program for Merge Sort 
#include<iostream> 
using namespace std; 

void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int A[], int size);

// Driver code 
int main(void) 
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
    mergeSort ( arrays, num);
    cout << "Arrays after sorting: ";
    display ( arrays, num);
} 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int left, int middle, int right) 
{ 
	int n1 = middle - left + 1; 
	int n2 = right - middle; 

	// Create temp arrays 
	int Left[n1], Right[n2]; 

	// Copy data to temp arrays L[] and R[] 
	for(int i = 0; i < n1; i++) 
		Left[i] = arr[left + i]; 
	for(int j = 0; j < n2; j++) 
		Right[j] = arr[middle + 1 + j]; 

	// Merge the temp arrays back into arr[l..r] 
	
	// Initial index of first subarray 
	int FirstSubArr = 0; 
	
	// Initial index of second subarray 
	int SecondSubArr = 0; 
	
	// Initial index of merged subarray 
	int MergeSubArr = left; 
	
	while (FirstSubArr < n1 && SecondSubArr < n2) 
	{ 
		if (Left[FirstSubArr] <= Right[SecondSubArr]) 
		{ 
			arr[MergeSubArr] = Left[FirstSubArr]; 
			FirstSubArr++; 
		} 
		else
		{ 
			arr[MergeSubArr] = Right[SecondSubArr]; 
			SecondSubArr++; 
		} 
		MergeSubArr++; 
	} 

	// Copy the remaining elements of 
	// L[], if there are any 
	while (FirstSubArr < n1) 
	{ 
		arr[MergeSubArr] = Left[FirstSubArr]; 
		FirstSubArr++; 
		MergeSubArr++; 
	} 

	// Copy the remaining elements of 
	// R[], if there are any 
	while (SecondSubArr < n2) 
	{ 
		arr[MergeSubArr] = Right[SecondSubArr]; 
		SecondSubArr++; 
		MergeSubArr++; 
	} 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted */ 
void mergeSort(int arr[], int left, int right) 
{ 
	if (left < right) 
	{ 
		
		// Same as (l+r)/2, but avoids 
		// overflow for large l and h 
		int middle = left + (right - left) / 2; 

		// Sort first and second halves 
		mergeSort(arr, left, middle); 
		mergeSort(arr, middle + 1, right); 

		merge(arr, left, middle, right); 
	} 
} 

// UTILITY FUNCTIONS 
// Function to print an array 
void printArray(int A[], int size) 
{ 
	for(int i = 0; i < size; i++) 
		cout << A[i] << " "; 
} 

