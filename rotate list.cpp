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

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *curr = head;
    int n = 1;
    while (curr->next)
    {
        curr = curr->next;
        n++;
    }
    curr->next = head;
    for (int i = 0; i < n - k % n; i++)
    {
        curr = curr->next;
    }
    ListNode *result = curr->next;
    curr->next = nullptr;
    return result;
}