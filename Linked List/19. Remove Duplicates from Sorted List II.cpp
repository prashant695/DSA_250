// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;

        while (p and p->next and p->next->next)
        {
            if (p->next->val == p->next->next->val)
            {
                ListNode *tmp = p;
                int x = p->next->val;
                ListNode *prev1 = NULL, *prev2 = NULL;
                while (p->next and p->next->val == x)
                {
                    p = p->next;
                    prev2 = prev1;
                    prev1 = p;

                    delete (prev2);
                }

                tmp->next = p->next;
                p = tmp;
            }

            else
                p = p->next;
        }

        return dummy->next;
    }
};