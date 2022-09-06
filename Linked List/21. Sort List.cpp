// https://leetcode.com/problems/sort-list/

// Insertion Sort
// https://leetcode.com/problems/insertion-sort-list/

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = head, *prev = dummy;

        while (curr)
        {
            if (curr->next and curr->next->val < curr->val)
            {
                while (prev->next and prev->next->val < curr->next->val)
                    prev = prev->next;

                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = dummy;
            }
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};

// Merge Sort
// https://leetcode.com/problems/sort-list/

class Solution
{
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *curr = new ListNode(0);
        ListNode *tmp = curr;
        while (head1 and head2)
        {
            if (head1->val < head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1)
            curr->next = head1;
        if (head2)
            curr->next = head2;

        return tmp->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL or !head->next)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};