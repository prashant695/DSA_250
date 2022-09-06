// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {

        if (head == NULL)
            return NULL;

        if (head->child)
        {
            Node *next = flatten(head->next);
            Node *child = flatten(head->child);

            head->next = child;
            child->prev = head;

            while (child and child->next)
                child = child->next;

            child->next = next;

            if (next)
                next->prev = child;

            head->child = NULL;
        }
        else
        {
            Node *next = flatten(head->next);
            head->next = next;
        }
        return head;
    }
};