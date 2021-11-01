#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
  int age;
  char name[25];
} data, temp;

void display(student data[], int size);
void bubblesort(student data[], int size);
void insertionsort(student data[], int size);
void merge(student data[], int a, int b, int c);
void mergesort(student data[], int l, int r);

int main()
{
  int i, n, method;
  char repeat;
  printf("---------------Welcome to the Age Sorting Algorithm Program---------------\n");
  printf("\nEnter the number of person:");
  scanf("%d", &n);
  student data[n];
  printf("\nEnter the person's info as name , age\n");
  for (i = 0; i < n; i++)
  {
    printf("Person %d:", i + 1);
    scanf("%s %d", data[i].name, &data[i].age);
  }
  // for Merge sort
  int data_size = sizeof(data) / sizeof(data[0]);

  do
  {
    printf("\nSelect a sorting method:\nPress 1 for Bubble Sorting Method.\nPress 2 for Instertion Method.\nPress 3 for Merge Sorting Method\n");
    scanf("%d", &method);
    switch (method)
    {
    case 1:
      printf("Sorting Algorithm: Bubble Sort\n-------------------------------------------------\nBefore Sorting\n");
      display(data, n);
      printf("-------------------------------------------------\nAfter Sorting\n");
      bubblesort(data, n);
      break;
    case 2:
      printf("Sorting Algorithm: Insertion Sort\n-------------------------------------------------\nBefore Sorting\n");
      display(data, n);
      printf("-------------------------------------------------\nAfter Sorting\n");
      insertionsort(data, n);
      break;
    case 3:
      printf("Sorting Algorithm: Merge Sort\n\nBefore Sorting\n");
      display(data, n);
      printf("After Sorting\n");
      mergesort(data, 0, n - 1);
      display(data, data_size);
      break;
    default:
      printf("Invalid Input.");
      break;
    }
    printf("Do you want to try another one? Y or N?\n");
    scanf("%s", &repeat);
  } while (repeat == 'Y');
}

void display(student data[], int size)
{
  printf("-------------------------------------------------\n");
  printf("NAME\t\t\t\tAGE");
  for (int i = 0; i < size; ++i)
  {
    printf("\n%s\t\t\t\t%d years old", data[i].name, data[i].age);
  }
  printf("\n");
}

void bubblesort(student data[], int size)
{

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step)
  {

    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i)
    {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (data[i].age > data[i + 1].age)
      {

        // swapping occurs if elements
        // are not in the intended order
        temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
      }
    }
  }
  display(data, size);
}

void insertionsort(student data[], int size)
{
  for (int step = 1; step < size; step++)
  {
    char tempnames[20];
    strcpy(tempnames, data[step].name);
    int key = data[step].age;
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<data[j] to key>data[j].
    while (key < data[j].age && j >= 0)
    {
      data[j + 1].age = data[j].age;
      strcpy(data[j + 1].name, data[j].name);
      --j;
    }
    strcpy(data[j + 1].name, tempnames);
    data[j + 1].age = key;
  }
  display(data, size);
}

// Merge two subarrays L and M into arr
void merge(student data[], int p, int q, int r)
{

  // Create L ? A[p..q] and M ? A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  student L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = data[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = data[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    if (L[i].age <= M[j].age)
    {
      data[k] = L[i];
      i++;
    }
    else
    {
      data[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    data[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    data[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergesort(student data[], int l, int r)
{
  if (l < r)
  {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergesort(data, l, m);
    mergesort(data, m + 1, r);

    // Merge the sorted subarrays
    merge(data, l, m, r);
  }
}
