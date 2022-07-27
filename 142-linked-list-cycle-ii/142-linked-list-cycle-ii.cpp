/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL or head->next==NULL){
            return NULL;
        }
        
        ListNode*slow = head;
        ListNode*fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast){
                break;
            }
        }
        
        if(slow == fast){
            
            slow = head;
            
            if(slow == fast){
                while(fast->next != slow){
                    fast = fast->next;
                }
            }
            else{
                while(fast->next != slow->next){
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            
            return fast->next;
        }
        
        return NULL;
    }
};