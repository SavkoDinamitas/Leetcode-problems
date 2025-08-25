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

ListNode *mergeLists(vector<ListNode *> &lists, int l, int r)
{
    if (l == r)
        return lists[l];

    int m = (l + r) / 2;
    return merge(mergeLists(lists, l, m), mergeLists(lists, m + 1, r));
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    return mergeLists(lists, 0, lists.size() - 1);
}

// iterative solution
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    int n = lists.size();

    while (n > 1)
    {
        int idx = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (i + 1 < n)
                lists[idx++] = merge(lists[i], lists[i + 1]);
            else
                lists[idx++] = lists[i];
        }
        n = idx;
    }
    return lists[0];
}