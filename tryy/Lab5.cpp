#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef int BSTElementType;

typedef struct BinaryTreeNode
{
    BSTElementType userID;
    BSTElementType count;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef BinaryTreeNode BSTNode;

static void PrintArray(const char *tag, int n, BSTNode *array)
{
    printf("%s:\n", tag);
    for (int i = 0; i < n; i++)
        printf("%2d: u = %4d, c = %2d\n", i, array[i].userID, array[i].count);
    putchar('\n');
    fflush(stdout);
}

static
void Merge(BSTNode *arr, int low, int mid, int high)
{
    int mergedSize = high - low + 1;
    BSTNode *temp = (BSTNode *)malloc(mergedSize * sizeof(BSTNode));
    int mergePos = 0;
    int leftPos = low;
    int rightPos = mid + 1;

    //printf("-->> %s: lo = %d, md = %d, hi = %d, sz = %d\n", __func__, low, mid, high, mergedSize);

    //printf("L = %d, M = %d; R = %d, H = %d\n", leftPos, mid, rightPos, high);
    while (leftPos <= mid && rightPos <= high)      // Key change
    {
        //printf("a[%d].c = %d <=> a[%d].c = %d\n", leftPos, arr[leftPos].count,
        //       rightPos, arr[rightPos].count);
        if (arr[leftPos].count < arr[rightPos].count)
        {
            //printf("L1: a[%d].c = %d\n", leftPos, arr[leftPos].count);
            temp[mergePos++] = arr[leftPos++];
        }
        else
        {
            //printf("R1: a[%d].c = %d\n", rightPos, arr[rightPos].count);
            temp[mergePos++] = arr[rightPos++];
        }
        //printf("L = %d, M = %d; R = %d, H = %d\n", leftPos, mid, rightPos, high);
    }

    while (leftPos <= mid)
    {
        //printf("L2: a[%d].c = %d\n", leftPos, arr[leftPos].count);
        temp[mergePos++] = arr[leftPos++];
    }

    while (rightPos <= high)
    {
        //printf("R2: a[%d].c = %d\n", rightPos, arr[rightPos].count);
        temp[mergePos++] = arr[rightPos++];
    }

    assert(mergePos == mergedSize);

    //PrintArray("merged", mergedSize, temp);

    for (mergePos = 0; mergePos < mergedSize; ++mergePos)
        arr[low + mergePos] = temp[mergePos];

    free(temp);         // Key change
    //printf("<<-- %s: lo = %d, md = %d, hi = %d, sz = %d\n", __func__, low, mid, high, mergedSize);
}

static
void MergeSort(BSTNode *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        //printf("-->> %s: lo = %d, md = %d, hi = %d\n", __func__, low, mid, high);

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        Merge(arr, low, mid, high);
        //printf("<<-- %s: lo = %d, md = %d, hi = %d\n", __func__, low, mid, high);
    }
}

int main(void)
{
    /* Unstable when testing */
    //srand(time(0));
    //int maxUsers = rand() % 20 + 5;
    /* Stable while debugging */
    int maxUsers = 10;

    BSTNode *arr = (BSTNode *)malloc(maxUsers * sizeof(BSTNode));

    for (int i = 0; i < maxUsers; i++)
    {
        arr[i].userID = rand() % 100 * 100;
        arr[i].count = rand() % 10;
        arr[i].left = 0;
        arr[i].right = 0;
    }

    PrintArray("Before", maxUsers, arr);
    MergeSort(arr, 0, maxUsers - 1);        // Key change
    PrintArray("After", maxUsers, arr);

    free(arr);

    return 0;
}