#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    while (fast && fast->next)
    {
        head = head->next;
        fast = fast->next->next;
        if (head == fast)
            return true;
    }
    return false;
}