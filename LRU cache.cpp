#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class LRUCache
{
private:
    unordered_map<int, ListNode *> map;
    int c;
    ListNode *curr;
    ListNode *head;

public:
    LRUCache(int capacity)
    {
        c = capacity;
    }

    int get(int key)
    {
        if (map[key]->prev && map[key]->next)
        {
            map[key]->prev->next = map[key]->next;
            map[key]->next->prev = map[key]->prev;
        }
        else if (head = map[key])
        {
            head = map[key]->next;
        }

        if (curr != map[key])
        {
            curr->next = map[key];
            map[key]->prev = curr;
            curr = map[key];
        }

        return map[key]->val;
    }

    void put(int key, int value)
    {
        if (!map[key])
        {
            if (c != 0)
            {
                ListNode *newNode = new ListNode(value);
                if (!head)
                {
                    head = newNode;
                    curr = newNode;
                }
                else
                {
                    curr->next = newNode;
                    newNode->prev = curr;
                    curr = newNode;
                }
                map[key] = newNode;
            }
            else
            {
                ListNode *newNode = new ListNode(value, head->next, nullptr);
                head->next->prev = newNode;
                map[head->val] = nullptr;
                head = newNode;
                map[key] = newNode;
            }
            c--;
        }
        else
        {
            if (map[key]->prev && map[key]->next)
            {
                map[key]->prev->next = map[key]->next;
                map[key]->next->prev = map[key]->prev;
            }
            else if (head = map[key])
            {
                head = map[key]->next;
            }

            if (curr != map[key])
            {
                curr->next = map[key];
                map[key]->prev = curr;
                curr = map[key];
            }
        }
    }
};

// working version
struct Node
{
    int key, val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(Node *node)
    {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int cap) : capacity(cap)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        Node *node = it->second;
        removeNode(node);
        addToTail(node);
        return node->val;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);

        if (it != cache.end())
        {
            Node *node = it->second;
            node->val = value;
            removeNode(node);
            addToTail(node);
        }
        else
        {
            if (cache.size() == capacity)
            {
                Node *lru = head->next;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node *newNode = new Node(key, value);
            cache[key] = newNode;
            addToTail(newNode);
        }
    }

    ~LRUCache()
    {
        Node *curr = head;
        while (curr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};