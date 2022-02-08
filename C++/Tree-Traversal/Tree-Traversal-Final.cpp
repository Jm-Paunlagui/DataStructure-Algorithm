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
        return root == NULL ? false : true; // ternary operator
    }

    // Recursive function to insert a node in the tree
    treeNode *insertNode(treeNode *r, treeNode *newNode)
    {
        // Root
        if (r == NULL)
        {
            cout << "Insertion successful!" << endl;
            return r = newNode;
        }

        // For the subtrees basically
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

    void print2DTree(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2DTree(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value << "\n";           // 6
        print2DTree(r->left, space);            // Process left child  7
    }

    // A function to print PreOrder traversal of a Binary Tree
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

    // A function to print InOrder traversal of a Binary Tree
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

    // A function to print PostOrder traversal of a Binary Tree
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
                objt.print2DTree(objt.root, 0);
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
                objt.print2DTree(objt.root, 0);
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
                objt.print2DTree(objt.root, 0);
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
                objt.print2DTree(objt.root, 0);
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