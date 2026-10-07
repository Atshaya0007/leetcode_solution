/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
     if (head == NULL || k == 1) {
        return head;
    }
    
    
    struct ListNode* curr = head;
    int count = 0;
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
    
   
    if (count < k) {
        return head;
    }
    
   
    curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* nextNode = NULL;
    
    for (int i = 0; i < k; i++) {
        nextNode = curr->next; 
        curr->next = prev;     
        prev = curr;           
        curr = nextNode;      
    }
    
   
    if (nextNode != NULL) {
        head->next = reverseKGroup(nextNode, k);
    }
    
   
    return prev;
}
