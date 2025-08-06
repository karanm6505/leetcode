/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
NODE* rotateOnce(NODE* head)
{
    if(head == NULL || head->next == NULL) return head;

    NODE* temp = head;
    NODE* prev = NULL;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    prev->next = NULL;
    head = temp;
    return head;
}
struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    int length = 0;
    NODE* temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if (length == 0) return head;

    for(int i = 0; i < k%length; i++)
    {
        head = rotateOnce(head);
    }
    return head;
}