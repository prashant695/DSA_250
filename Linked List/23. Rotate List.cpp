// https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head or !head->next)
            return head;

        int cnt = 0;

        ListNode *copyhead = head;

        while (copyhead)
        {
            cnt++;
            copyhead = copyhead->next;
        }

        k = k % cnt;

        if (k == 0 or k == cnt)
            return head;

        ListNode *fast = head, *slow = head;

        while (k--)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *tmp = slow->next;
        ListNode *newhead = tmp;
        slow->next = NULL;

        while (tmp && tmp->next)
            tmp = tmp->next;

        if (tmp)
            tmp->next = head;

        return newhead;
    }
};