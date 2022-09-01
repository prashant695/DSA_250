// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Method - 1
// Using Hashmap

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        map<ListNode *, int> m;

        while (head)
        {
            if (m[head])
                return 1;
            else
                m[head] = 1;

            head = head->next;
        }
        return 0;
    }
};

// Method - 2
// HARE AND TURTLE

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

// Method - 3
// Replace node value

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        while (head)
        {
            if (head->val == 100001)
                return 1;
            else
                head->val = 100001;

            head = head->next;
        }
        return 0;
    }
};