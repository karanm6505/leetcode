/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;
NODE* reverseList(NODE* head)
{
    NODE* prev = NULL;
    NODE* curr = head;
    NODE* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;        
        curr = next;        
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) 
{
    //find middle
    NODE* slow = head;
    NODE* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //rev
    NODE* secondHalf = reverseList(slow->next);
    NODE* firstHalf = head;

    NODE* temp = secondHalf;
    bool flag = true;
    while (temp != NULL)
    {
        if (firstHalf->val != temp->val)
        {
            flag = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    return flag;
}