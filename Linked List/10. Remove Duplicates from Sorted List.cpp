// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        while (p and p->next)
        {
            if (p->val == p->next->val)
            {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete (temp);
            }
            else
                p = p->next;
        }
        return head;
    }
};
