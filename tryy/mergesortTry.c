# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
# define MAX_CHARS_IN_NAME 30
# define NUMBER_OF_MONTHS 12
 
 typedef struct
{
    char first_name[MAX_CHARS_IN_NAME];
    char last_name[MAX_CHARS_IN_NAME];
    char month[10];
    int day;
    int year;
    int day_of_year;
} person;

void MergeSort(int values[], int start, int end);
void Merge(int values[], int start, int middle, int end);
void Print_Array(int values[], int length);
void Assign_Dates_To_Queried_Students(person *classmate, person *queried, int size);
void Convert_Student_Birthday_To_Day_of_Year(person *classmate, int size);
 
int main()
{
    // Create a file pointer and open the file
    FILE *ifp = fopen("birthday.txt", "r");
 
    // Test to see if the file opens
    if (!ifp)
    {
        printf("The file is unable to open!\n");
        return -1;
    }
 
    // Create variables for the number of classes, number of students in the class, birthday month/day/year, number of queried students, queried students
    int i, num_classes, num_students, num_queried;
 
     // Read in the number of classes. PROPERLY READ IN (TESTED)
    fscanf(ifp, "%d", &num_classes);
    //printf("The number of classes is %d\n", num_classes);
 
     // Read in the number of students in the class. PROPERLY READ IN (TESTED)
    fscanf(ifp, "%d", &num_students);
    //printf("The number of students is %d\n", num_students);

    // Allocating space for the students in the classroom
    person *student = malloc(sizeof(person)*num_students);
    // Allocating space for the queried student structures.
    person *queried_student = malloc(sizeof(person)*num_queried);
 
     for (i=0; i< num_students; i++)
    {
        // Scan in the student's first name, last name
        fscanf(ifp, "%s", student[i].first_name);
        fscanf(ifp, "%s", student[i].last_name);

        // Scan in the student's birth month, day, year
        fscanf(ifp, "%s", student[i].month);
        //printf("\n");
        //printf("the student's month is %s\n", student[i].month);
        fscanf(ifp, "%d", &student[i].day);
        fscanf(ifp, "%d", &student[i].year);
    }
    
    Convert_Student_Birthday_To_Day_of_Year(student, num_students);

    printf("\n");
    
    int date_array[num_students];
    printf("The unsorted array:\n");
    for (i=0; i< num_students; i++)
    {
        date_array[i] = student[i].day_of_year;
        printf("%d ", date_array[i]);
    } 
    printf("\n");

    MergeSort(date_array, 0, num_students-1);
    printf("The sorted array:\n");
    Print_Array(date_array, num_students);

    // Scan in the number of queried students
    fscanf(ifp, "%d", &num_queried);

    // For loop that reads in the queried student(s) first and last name
    for (i=0; i< num_queried; i++)
    {
        fscanf(ifp, "%s", queried_student[i].first_name);
        fscanf(ifp, "%s", queried_student[i].last_name);
        //printf("The queried student is %s %s\n", queried_student[i].first_name, queried_student[i].last_name);
    }

    // This function assigns dates to the queried students by searching the list of the classmates
    Assign_Dates_To_Queried_Students(student, queried_student, num_students);
    Convert_Student_Birthday_To_Day_of_Year(queried_student, num_queried);
    
    int queried_date_array[num_queried];
    for (i=0; i< num_queried; i++)
    {
        queried_date_array[i] = queried_student[i].day_of_year;
        printf("%d ", queried_date_array[i]);
    }
    printf("\n");
            
    // Compare queried_date array to the sorted date arrays
    //person *closest_date()

     // print output
 
    fclose(ifp);
    return 0;
}

void Merge(int values[], int start, int middle, int end) 
{

    //printf("merge %d, %d, %d\n", start, middle, end);
    
    int *temp, i, length, count1, count2, mc;
  
    // Allocate the proper amount of space for our auxiliary array.
    length = end - start + 1;
    temp = (int*)calloc(length, sizeof(int));

    // These will be our indexes into our two sorted lists.
    count1 = start;
    count2 = middle;
  
    // Keeps track of our index into our auxiliary array.
    mc = 0;

    // Here we copy values into our auxiliary array, so long as there are 
    // numbers from both lists to copy.
    while ((count1 < middle) || (count2 <= end)) {

        // Next value to copy comes from list one - make sure list
        // one isn't exhausted yet. Also make sure we don't access index
        // count2 if we aren't supposed to.
        if (count2 > end || (count1 < middle && values[count1] < values[count2])) {
            temp[mc] = values[count1];
            count1++;
            mc++;
        }
    
        // We copy the next value from list two.
        else {
            temp[mc] = values[count2];
            count2++;
            mc++;
        }
    }

    // Copy back all of our values into the original array.
    for (i=start; i<=end; i++)
        values[i] = temp[i - start];

    // Don't need this space any more!
    free(temp);
}

void MergeSort(int values[], int start, int end)
{
    int mid;
  
    // Check if our sorting range is more than one element.
    if (start < end) 
    {

        mid = (start+end)/2;
    
        // Sort the first half of the values.
        MergeSort(values, start, mid);
    
        // Sort the last half of the values.
        MergeSort(values, mid+1, end);
    
        // Put it all together.
        Merge(values, start, mid+1, end);
    }
}

void Print_Array(int values[], int length) 
{

    int i;
    for (i=0; i<length; i++)
        printf("%d ", values[i]);
}

void Assign_Dates_To_Queried_Students(person *classmate, person *queried, int size)
{
    // COMPARING THE QUERIED STUDENT'S NAMES WITH STUDENTS NAMES
    // THIS IS NECCESSARY BECAUSE THE STUDENTS DATA NEEDS TO BE COPIED TO THE QUERIED STUDENT
    int i = 0;
    int j = 0;

    while (i< size)
    {
        // If the names of the queried student matches the name of the student in the list
        if (strcmp(classmate[i].first_name, queried[j].first_name) == 0
            && strcmp(classmate[i].last_name, queried[j].last_name) == 0)
        {
            strcpy(classmate[i].first_name, queried[j].first_name);
            strcpy(classmate[i].last_name, queried[j].last_name);
            strcpy(queried[j].month, classmate[i].month);
            queried[j].day = classmate[i].day;
            queried[j].year = classmate[i].year;
            queried[j].day_of_year = classmate[i].day_of_year;
            //printf("\n");
            //printf("%s %s", classmate[i].first_name, classmate[i].last_name);
            //printf(" %s", classmate[i].month);
            //printf(" %d", classmate[i].day);
            //printf(" %d\n", classmate[i].year);
            i++;
            j++;
        }

        else
        {
            i++;
        }

    }

    printf("\n");
}

void Convert_Student_Birthday_To_Day_of_Year(person *classmate, int size)
{
    // Creating an integer first_day_of_month variable that will convert the month 
        // to the day of the year (e.g. March 1st = 60 because March 1st is the 60th day of the year...)
        
        // CREATE IF STATEMENTS FOR NON-FEB 29TH AND FEB 29TH'S
        
        // first_day_of_month is equal to the day of the year for the first of each month
        int first_day_of_month;
        int i;

        printf("\n");

        for (i=0; i< size; i++)
        {
            if (strcmp(classmate[i].month, "JANUARY") == 0)
            first_day_of_month = 1;
        
            else if (strcmp(classmate[i].month, "FEBRUARY") == 0)
                first_day_of_month = 32;
        
            else if (strcmp(classmate[i].month, "MARCH") == 0)
                first_day_of_month = 60;
        
            else if (strcmp(classmate[i].month, "APRIL") == 0)
                first_day_of_month = 91;
        
            else if (strcmp(classmate[i].month, "MAY") == 0)
                first_day_of_month = 121;
        
            else if (strcmp(classmate[i].month, "JUNE") == 0)
                first_day_of_month = 152;
        
            else if (strcmp(classmate[i].month, "JULY") == 0)
                first_day_of_month = 182;
        
            else if (strcmp(classmate[i].month, "AUGUST") == 0)
                first_day_of_month = 213;
        
            else if (strcmp(classmate[i].month, "SEPTEMBER") == 0)
                first_day_of_month = 244;
            
            else if (strcmp(classmate[i].month, "OCTOBER") == 0)
                first_day_of_month = 274;
        
            else if (strcmp(classmate[i].month, "NOVEMBER") == 0)
                first_day_of_month = 305;
        
            else
                first_day_of_month = 335;

            // This line of code changes the student's birthdays into the day of the year.
            classmate[i].day_of_year = first_day_of_month + (classmate[i].day - 1);
        
            //printf("%s %s's birthday is the %d day of the year!\n", classmate[i].first_name, classmate[i].last_name, 
            //                                                 classmate[i].day_of_year);
        }

}