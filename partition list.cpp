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

ListNode *partition(ListNode *head, int x)
{
    ListNode less(0);
    ListNode more(0);
    ListNode *l = &less;
    ListNode *m = &more;
    while (head)
    {
        if (head->val < x)
        {
            l->next = head;
            l = head;
        }
        else
        {
            m->next = head;
            m = head;
        }
        head = head->next;
    }
    l->next = more.next;
    m->next = nullptr;
    return less.next;
}