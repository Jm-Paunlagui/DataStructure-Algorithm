/**
 * @file Tree-Traversal-Final.cpp
 * @author Jm-Paunlagui (jmpaunlagui01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#define SPACE 10

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class treeNode
{
public:
    int value;
    treeNode *leftNode;
    treeNode *rightNode;

    treeNode()
    {
        value = 0;
        leftNode = NULL;
        rightNode = NULL;
    }
};

/* BTT functions */
class BTT
{
public:
    treeNode *root;
    BTT()
    {
        root = NULL;
    }

    // Checks if its empty or not
    bool isTreeEmpty()
    {
        return (root == NULL) ? false : true; // Ternary operator
    }

    // Recursive function to insert a key into a BTT
    // r for root
    // newNode for new node
    treeNode *insertNode(treeNode *r, treeNode *newNode)
    {
        // Root
        if (r == NULL)
        {
            cout << "Insertion successful!" << endl;
            return r = newNode;
        }

        // For the subtrees
        if (newNode->value < r->value)
        {
            r->leftNode = insertNode(r->leftNode, newNode);
        }
        else if (newNode->value > r->value)
        {
            r->rightNode = insertNode(r->rightNode, newNode);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }
        return r;
    }

    // A function to print preOrder traversal of a Binary Tree
    void printPreOrder(treeNode *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value << " ";
        /* then recur on left sutree */
        printPreOrder(r->leftNode);
        /* now recur on right subtree */
        printPreOrder(r->rightNode);
    }

    // A utility function to print inOrder traversal of a Binary Tree
    void printInOrder(treeNode *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInOrder(r->leftNode);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        printInOrder(r->rightNode);
    }

    // A utility function to print postOrder traversal of a Binary Tree
    void printPostOrder(treeNode *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree
        printPostOrder(r->leftNode);
        // then recur on right subtree
        printPostOrder(r->rightNode);
        // now deal with the node
        cout << r->value << " ";
    }
};

// Main driver code
int main()
{
    BTT objt;
    int option, nodeValue;

    do
    {
        cout << "\nPlease Select an option #\n1. Insert a Node \n2. Show Pre-Order Traversal\n3. Show In-order Traversal\n4. Show Post-Order Traversal\n5. Show all Traversals\n6. Clear Screen\n0. Exit\n-- ";
        cin >> option;

        treeNode *newNode = new treeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "\nPlease Insert a Node to the Binary Tree -";
            cin >> nodeValue;
            newNode->value = nodeValue;
            objt.root = objt.insertNode(objt.root, newNode);
            cout << endl;
            break;
        case 2:
            if (objt.isTreeEmpty())
            {
                cout << "\nPre-Order Traversal visits nodes in the following order: ";
                objt.printPreOrder(objt.root);
            }
            else
            {
                cout << "Empty Tree";
            }
            cout << endl;
            break;
        case 3:
            if (objt.isTreeEmpty())
            {
                cout << "\nIn-Order Traversal visits nodes in the following order: ";
                objt.printInOrder(objt.root);
            }
            else
            {
                cout << "Empty Tree";
            }
            cout << endl;
            break;
        case 4:
            if (objt.isTreeEmpty())
            {
                cout << "\nPost-Order Traversal visits nodes in the following order: ";
                objt.printPostOrder(objt.root);
            }
            else
            {
                cout << "Empty Tree";
            }
            cout << endl;
            break;
        case 5:
            if (objt.isTreeEmpty())
            {
                cout << "All Tree-Traversal\n";
                cout << "\nPre-Order Traversal visits nodes in the following order: ";
                objt.printPreOrder(objt.root);
                cout << endl;
                cout << "\nIn-Order Traversal visits nodes in the following order: ";
                objt.printInOrder(objt.root);
                cout << endl;
                cout << "\nPost-Order Traversal visits nodes in the following order: ";
                objt.printPostOrder(objt.root);
            }
            else
            {
                cout << "Empty Tree";
            }
            cout << endl;
            break;
        case 6: 
            system("cls");
        default:
            break;
        }
    } while (option != 0);
}