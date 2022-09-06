// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        
        while (p and p->next and p->next->next)
        {
            ListNode *a = p->next;
            ListNode *b = p->next->next;

            p->next = b;
            a->next = b->next;
            b->next = a;
            p = p->next->next;
        }

        return dummy->next;
    }
};