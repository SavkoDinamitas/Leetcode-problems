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

bool kMore(ListNode *head, int k)
{
    if (!head)
        return false;
    int i = 1;
    ListNode *curr = head;
    while (curr->next && i < k)
    {
        i++;
        curr = curr->next;
    }
    return k == i;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1)
        return head;
    ListNode dummy(0);
    ListNode *pk = &dummy, *tp;
    ListNode *left = head, *right = head->next;
    while (kMore(left, k))
    {
        int i = 1;
        tp = left;
        while (i++ < k)
        {
            tp->next = right->next;
            right->next = left;
            left = right;
            right = tp->next;
        }
        pk->next = left;
        pk = tp;
        left = right;
        if (right)
            right = right->next;
    }
    return dummy.next;
}