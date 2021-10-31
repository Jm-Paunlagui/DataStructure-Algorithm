#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STUDENTS 3
#define NUM_TUD_STUDENTS 30

// Structure template
typedef struct student_record
{
    char name[48];
    int ID;
    int age;
    float height;
    float weight;
}Record;

// Function Prototypes
void combine_lists(Record[], Record[], Record[], Record[]);
void merge_sort(Record[], int, int);
void merge(Record[], int, int, int);

int main()
{
    int low = 0, high = NUM_TUD_STUDENTS;
    int i;

    // Struct arrays. TUD, DIT, ITT and ITB are acronyms for college names.
    Record TUD[NUM_TUD_STUDENTS], DIT[NUM_STUDENTS],
    ITT[NUM_STUDENTS], ITB[NUM_STUDENTS];

    // File pointers
    // FILE *fp1, *fp2, *fp3;

    // // Open the files for reading
    // fp1 = fopen("DIT_Student_List.txt", "r");
    // fp2 = fopen("ITT_Student_List.txt", "r");
    // fp3 = fopen("ITB_Student_List.txt", "r");

    // // Check for error
    // if(fp1 == NULL || fp2 == NULL || fp3 == NULL)
    // {
    //     printf("Error opening files.\n");
    // }
    // else
    // {
        // Read in the first list of students
        for(i = 0; i < NUM_STUDENTS; i++)
        {
            scanf( "%s %d %d %f %f", DIT[i].name, &DIT[i].ID, &DIT[i].age,
                   &DIT[i].height, &DIT[i].weight);
        }

        // Read in the second list of students
        for(i = 0; i < NUM_STUDENTS; i++)
        {
            scanf( "%s %d %d %f %f", ITT[i].name, &ITT[i].ID, &ITT[i].age,
                   &ITT[i].height, &ITT[i].weight);
        }

        // Read in the third list of students
        for(i = 0; i < NUM_STUDENTS; i++)
        {
            scanf("%s %d %d %f %f", ITB[i].name, &ITB[i].ID, &ITB[i].age,
                   &ITB[i].height, &ITB[i].weight);
        }

        // Call the function to combine the three lists
        combine_lists(TUD, DIT, ITT, ITB);

        // Sorting function
        merge_sort(TUD, low, high);

        // Display list of students after sorting
        for(i = 0; i < NUM_TUD_STUDENTS; i++)
        {
            printf( "%s\n %d\n %d\n %f\n %f\n", TUD[i].name, TUD[i].ID,
                TUD[i].age, TUD[i].height, TUD[i].weight);
        }
    //}

    // // Close the pointers
    // fclose(fp1);
    // fclose(fp2);
    // fclose(fp3);

    return 0;
}// end main()

void combine_lists(Record tud[], Record dit[], Record itt[], Record itb[])
{
    int i = 0;

    // Combines all three lists into one list
    for(i = 0; i < 30; i++)
    {
        if(i < 10)
        {
            strcpy(tud[i].name, dit[i].name);
            tud[i].ID = dit[i].ID;
            tud[i].age = dit[i].age;
            tud[i].height = dit[i].height;
            tud[i].weight = dit[i].weight;
        }

        if(i > 9 && i < 20)
        {
            strcpy(tud[i].name, itt[i - 10].name);
            tud[i].ID = itt[i - 10].ID;
            tud[i].age = itt[i - 10].age;
            tud[i].height = itt[i - 10].height;
            tud[i].weight = itt[i - 10].weight;
        }

        if(i > 19)
        {
            strcpy(tud[i].name, itb[i - 20].name);
            tud[i].ID = itb[i - 20].ID;
            tud[i].age = itb[i - 20].age;
            tud[i].height = itb[i - 20].height;
            tud[i].weight = itb[i - 20].weight;
        }
    }
}// end combine_lists()

void merge_sort(Record a[], int low, int high)
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

void merge(Record a[], int low, int mid, int high)
{
    int i;
    int left_index = low;
    int right_index = mid + 1;
    int combined_index = low;

    /*
        There is a problem here. When I set tempA to 30, the size of the combined struct arrays,
        the program crashes. However, setting it to a higher value stops that from happening.
        I don't see that as a reasonable solution however, as I don't know the cause of the crashes.
    */
    Record tempA[31];

    while(left_index <= mid && right_index <= high)
    {
        // When trying to sort by age, it sorts by ID and vice versa.
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