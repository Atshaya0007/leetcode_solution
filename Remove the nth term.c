#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node pointing to the head
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;
    
    // Advance the fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast != NULL) {
            fast = fast->next;
        }
    }
    
    // Move both pointers until fast reaches the last node
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow->next is now the node to be deleted
    struct ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    
    // Free the memory of the removed node
    free(toDelete);
    
    // Return the new head (handles case if head was deleted)
    return dummy.next;
}
