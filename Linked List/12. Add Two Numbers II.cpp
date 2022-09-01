// https://leetcode.com/problems/add-two-numbers-ii/submissions/

// Method - 1
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
// Reversing the lists and then performing the addition operation
// Reversing the output list as well

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *first = NULL, *second = head, *temp = NULL;

        while (second)
        {
            temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        return first;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *t = dummy;
        int c = 0;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        while (c || l1 || l2)
        {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            t->next = new ListNode(c % 10);
            t = t->next;
            c /= 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        dummy->next = reverseList(dummy->next);
        return dummy->next;
    }
};

// Method - 2
// Add zeros in the begining of smaller list so as to make the 2 lists of same size
// then perform the addition operation from the end

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Adding zeros to the start of the smaller list:

        // l1: 7->2->4->3
        // l2: 5->6->4

        // After adding zeros
        // l1: 7->2->4->3
        // l2: 0->5->6->4

        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr1 != NULL || ptr2 != NULL)
        {
            if (ptr1 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;

                ptr2 = ptr2->next;
            }
            else if (ptr2 == NULL)
            {
                ListNode *newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;

                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        // Main operation:
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = addTwoDigit(l1, l2, carry);
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }

        return dummy->next;
    }

    ListNode *addTwoDigit(ListNode *l1, ListNode *l2, int &carry)
    {
        if (l1 == NULL && l2 == NULL)
            return NULL;

        ListNode *newNode = new ListNode(-1);
        newNode->next = addTwoDigit(l1->next, l2->next, carry);

        newNode->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;

        return newNode;
    }
};