#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct node
{
    int value;
    struct node *next;
};
// Function declaration
void insert();
void deleteNode();
void displays();
void count();

typedef struct node DATA_NODE;

DATA_NODE *headNode, *firstNode, *tempNode = 0, *prevNode, nextNode;
int data;

int main(void)
{
    int option = 0;

    cout << "Singly Linked List C++ example - All Operations\n";

    while (option < 5)
    {
        cout << "\n Options \n";
        cout << "1: Insert into Linked list\n"
            << "2: Delete from Linked list\n"
            << "3: Display Linked list\n"
            << "4: Count Linked list\n"
            << " Others: Exit()\n"
            << "Enter your option: ";
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            displays();
            break;
        case 4:
            count();
            break;
        default:
            break;
        }
    }
}

void insert()
{
    cout << "\n Enter element for Insert Linked list :\n";
    scanf("%d", &data);

    tempNode = (DATA_NODE *)malloc(sizeof(DATA_NODE));
    tempNode->value = data;

    if (firstNode == 0)
    {
        firstNode = tempNode;
    }
    else
    {
        headNode->next = tempNode;
    }
    tempNode->next = 0;
    headNode = tempNode;
    fflush(stdin);
}

void deleteNode()
{
    int countValue = 0, position, index = 0;
    countValue = count();
    tempNode = firstNode;

    cout << "\n Display Linked list \n";

    cout << "\n Enter position for Delete Element : \n";
    scanf("%d", &position);

    if (position > 0 && position <= countValue)
    {
        if (position == 1)
        {
            tempNode = tempNode->next;
            firstNode = tempNode;
            cout << "\n Deleted Successfully \n";
        }
        else
        {
            while (tempNode != 0)
            {
                if (index == (position - 1))
                {
                    prevNode->next = tempNode->next;
                    if (index == (countValue - 1))
                    {
                        headNode = prevNode;
                    }
                    cout << "\n Deleted Successfully \n";
                    break;
                }
                else
                {
                    index++;
                    prevNode = tempNode;
                    tempNode = tempNode->next;
                }
            }
        }
    }
    else
    {
        cout << "\n Invalid Position! \n";
    }
}

void displays()
{
    int count = 0;
    tempNode = firstNode;
    cout << "Linked list :\n";

    while (tempNode != 0)
    {
        cout << "# " << tempNode->value;
        count++;
        tempNode = tempNode->next;
    }
    cout << "\nNo of items in linked list : %d" << count;
}

void count()
{
    int count = 0;
    tempNode = firstNode;

    while (tempNode != 0)
    {
        count++;
        tempNode = tempNode->next;
    }
    cout << "\nNo of items in linked list : %d" << count;
}
