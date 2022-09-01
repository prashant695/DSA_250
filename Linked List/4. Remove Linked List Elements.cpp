// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;

        while (p)
        {
            if (p->next and p->next->val == val)
            {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            else
                p = p->next;
        }

        return dummy->next;
    }
};