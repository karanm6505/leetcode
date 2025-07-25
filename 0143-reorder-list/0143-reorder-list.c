/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
void reorderList(struct ListNode* head) 
{
    NODE* slow = head;
    NODE* fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    NODE* half = slow->next;
    NODE* prev = slow->next = NULL;
    while (half != NULL)
    {
        NODE* temp = half->next;
        half->next = prev;
        prev = half;
        half = temp;
    }
    NODE* first = head;
    half = prev;
    while(half != NULL)
    {
        NODE* temp1 = first->next;
        NODE* temp2 = half->next;
        first->next = half;
        half->next = temp1;
        first = temp1;
        half = temp2;
    }
}