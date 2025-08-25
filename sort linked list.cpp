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

ListNode *merge(ListNode *first, ListNode *second)
{
    ListNode dummy(0);
    ListNode *curr = &dummy;
    while (first && second)
    {
        if (first->val < second->val)
        {
            curr->next = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }
    if (first)
        curr->next = first;
    if (second)
        curr->next = second;
    return dummy.next;
}

ListNode *sortList(ListNode *head)
{
    if (!head)
        return nullptr;
    if (!head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *right = slow->next;
    slow->next = nullptr;

    return merge(sortList(head), sortList(right));
}

// funny itterative solution
ListNode *split(ListNode *head, int step)
{
    for (int i = 1; head && i < step; i++)
    {
        head = head->next;
    }
    if (!head)
        return nullptr;

    ListNode *second = head->next;
    head->next = nullptr;
    return second;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    int n = 0;
    for (ListNode *p = head; p; p = p->next)
        n++;

    ListNode dummy(0);
    dummy.next = head;

    for (int step = 1; step < n; step *= 2)
    {
        ListNode *prev = &dummy;
        ListNode *curr = dummy.next;

        while (curr)
        {
            ListNode *left = curr;
            ListNode *right = split(left, step);
            curr = split(right, step);

            prev->next = merge(left, right);

            while (prev->next)
                prev = prev->next;
        }
    }

    return dummy.next;
}