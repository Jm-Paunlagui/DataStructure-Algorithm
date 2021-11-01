#include <stdio.h>
#include <stdlib.h>

// Structure template
typedef struct
{
    char firstname[20];
    char surname[20];
    int age;
}Person;

// Function Prototypes
void merge_sort(Person[], int, int);
void merge(Person[], int, int, int);

int main()
{
    // Struct array to hold people's data
    Person list[3];

    // File pointer for file operations
    FILE *fp;

    int i = 0;
    int low = 0, high = 0;

    // Open the file
    fp = fopen("list_of_people.txt", "r");

    // If error
    if(fp == NULL)
    {
        puts("Error opening file.\n");
    }
    else
    {
        // Read in contents of file and store in struct array
        for(i = 0; i < 3; i++)
        {
            fscanf(fp, "%s %s %d", list[i].firstname, list[i].surname, &list[i].age);
        }

        // Function Call
        merge_sort(list, low, high);

        // Print contents after sorting
        for(i = 0; i < 3; i++)
        {
            fprintf(stdout, "%s %s\n %d\n", list[i].firstname, list[i].surname, list[i].age);
        }
    }

    return 0;
}// end main()

void merge_sort(Person a[], int low, int high)
{
    int mid = 0;

    if(low == high)
    {
        return;
    }
    else
    {
        mid = (low + high) / 2;

        merge_sort(a, low, mid);

        merge_sort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}// end merge_sort()

void merge(Person a[], int low, int mid, int high)
{
    int i;
    int left_index = low;
    int right_index = mid + 1;
    int combined_index = low;
    Person tempA[10];

    while(left_index <= mid && right_index <= high)
    {
        if(a[left_index].age <= a[right_index].age)
        {
            tempA[combined_index++] = a[left_index++];
        }
        else
        {
            tempA[combined_index++] = a[right_index++];
        }
    }

    if(left_index == mid + 1)
    {
        while(right_index <= high)
        {
            tempA[combined_index++] = a[right_index++];
        }
    }
    else
    {
        while(left_index <= mid)
        {
            tempA[combined_index++] = a[left_index++];
        }
    }

    for(i = low; i <= high; i++)
    {
        a[i] = tempA[i];
    }
}// end merge() 