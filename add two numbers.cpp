#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode((l1->val + l2->val) % 10);
    int left = (l1->val + l2->val) / 10;
    l1 = l1->next;
    l2 = l2->next;
    ListNode *curr = head;
    while (l1 || l2)
    {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        curr->next = new ListNode((v1 + v2 + left) % 10);
        left = (v1 + v2 + left) / 10;
        curr = curr->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (left == 1)
    {
        curr->next = new ListNode(1);
    }
    return head;
}