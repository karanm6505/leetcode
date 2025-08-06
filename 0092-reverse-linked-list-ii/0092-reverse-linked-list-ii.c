/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    if (head == NULL || left == right) return head;

    NODE dummy;
    dummy.next = head;
    NODE* prev = &dummy;

    for (int i = 1; i < left; i++) {
        if (prev == NULL) return NULL;
        prev = prev->next;
    }

    NODE* curr = prev->next;
    NODE* then = curr->next;

    for (int i = 0; i < right - left; i++) {
        curr->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = curr->next;
    }

    return dummy.next;
}
