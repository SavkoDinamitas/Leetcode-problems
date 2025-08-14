#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEndTrick(ListNode *head, int n)
{
    ListNode dummy(0);
    dummy.next = head;

    ListNode *first = &dummy;
    ListNode *second = &dummy;

    for (int i = 0; i < n + 1; i++)
    {
        first = first->next;
    }

    while (first)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy.next;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int size = 0;
    if (!head)
        return head;
    ListNode *curr = head;
    while (curr)
    {
        size++;
        curr = curr->next;
    }

    if (size == 1)
        return nullptr;

    curr = head;
    for (int i = 0; i < size - n - 1; i++)
    {
        curr = curr->next;
    }

    if (size == n)
        return head->next;

    curr->next = curr->next->next;
    return head;
}