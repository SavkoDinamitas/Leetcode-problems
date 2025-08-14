#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomListDiff(Node *head)
{
    if (!head)
        return nullptr;

    Node *curr = head;
    while (curr)
    {
        Node *copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }

    curr = head;
    while (curr)
    {
        if (curr->random)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    Node *copyhead = head->next;
    curr = head;
    while (curr)
    {
        Node *copy = curr->next;
        curr->next = copy->next;
        if (copy->next)
        {
            copy->next = copy->next->next;
        }
        curr = curr->next;
    }
    return copyhead;
}

Node *copyRandomList(Node *head)
{
    Node *copy = new Node(head->val);
    unordered_map<Node *, Node *> connections;
    connections[head] = copy;
    Node *result = copy;
    while (head)
    {
        if (head->next)
        {
            if (connections[head->next])
            {
                copy->next = connections[head->next];
            }
            else
            {
                copy->next = new Node(head->next->val);
                connections[head->next] = copy->next;
            }
        }
        if (head->random)
        {
            if (connections[head->random])
            {
                copy->random = connections[head->random];
            }
            else
            {
                copy->random = new Node(head->random->val);
                connections[head->random] = copy->random;
            }
        }

        head = head->next;
        copy = copy->next;
    }
    return result;
}