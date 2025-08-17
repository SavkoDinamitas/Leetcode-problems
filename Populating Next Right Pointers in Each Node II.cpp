#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
        return root;

    Node *head = root;
    while (head)
    {
        Node dummy(0);
        Node *temp = &dummy;
        for (Node *curr = head; curr; curr = curr->next)
        {
            if (curr->left)
            {
                temp->next = curr->left;
                temp = temp->next;
            }
            if (curr->right)
            {
                temp->next = curr->right;
                temp = temp->next;
            }
        }
        head = dummy.next;
    }
    return root;
}