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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode dummy(0);
    ListNode *curr = head;
    ListNode *ok = &dummy;

    while (curr)
    {
        bool entered = false;
        while (curr->next && curr->val == curr->next->val)
        {
            entered = true;
            curr = curr->next;
        }
        if (!entered)
        {
            ok->next = curr;
            ok = ok->next;
        }

        curr = curr->next;
    }
    ok->next = nullptr;
    return dummy.next;
}