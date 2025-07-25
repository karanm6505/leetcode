/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
struct ListNode* removeNthFromEnd(struct ListNode* head, int pos) 
{
    int length = 0;
    NODE* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    pos = length - pos + 1;
    if(head == NULL || pos < 1)
        return NULL;
    
    if(pos == 1)
    {
        if(head == NULL)
        return NULL;
        NODE* temp = head;
        head = temp->next;
        free(temp);
        return head;
    }

    NODE* curr = head;
    NODE* prev = NULL;
    int count = 1;

    while(curr != NULL && count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr == NULL)
        return head;

    prev->next = curr->next;
    free(curr);
    return head;
}