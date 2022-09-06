// https://leetcode.com/problems/partition-list/

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

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *t1 = new ListNode(), *t2 = new ListNode();
        ListNode *h1 = t1, *h2 = t2;
        int flg = 0;
        while (head)
        {
            if (head->val < x)
            {
                t1->next = head;
                t1 = t1->next;
            }
            else
            {
                t2->next = head;
                t2 = t2->next;
            }
            head = head->next;
        }
        t2->next = NULL;
        t1->next = h2->next;
        return h1->next;
    }
};