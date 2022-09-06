// https://leetcode.com/problems/reorder-list/

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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *first = NULL, *second = head;
        ListNode *temp = NULL;

        while (second)
        {
            temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }

        return first;
    }
    void merge(ListNode *l1, ListNode *l2)
    {
        while (l2)
        {
            ListNode *next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast and fast->next and fast->next->next)
        {

            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l2 = slow->next, *l1 = head;
        slow->next = NULL;
        l2 = reverseList(l2);

        merge(l1, l2);
    }
};