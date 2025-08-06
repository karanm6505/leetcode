/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
void deleteNode(struct ListNode* node) 
{
    if (node == NULL || node->next == NULL) return; 

    NODE* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    free(nextNode);
}