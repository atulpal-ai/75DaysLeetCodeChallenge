/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Step 1: move fast n steps
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        
        // Step 2: move both
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        // Step 3: delete node
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};