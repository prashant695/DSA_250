// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int cnt = -1, res = 0;
        ListNode *p = head;
        while (p)
        {
            cnt++;
            p = p->next;
        }

        while (head)
        {
            res += pow(2, cnt--) * head->val;
            head = head->next;
        }
        return res;
    }
};

// Method - 2

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
    int getDecimalValue(ListNode *head)
    {
        head = reverseList(head);
        int cnt = 0, res = 0;
        while (head)
        {
            res += pow(2, cnt++) * head->val;
            head = head->next;
        }
        return res;
    }
};

// Method - 3

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count = (count << 1) | head->val;
            head = head->next;
        }
        return count;
    }
};
