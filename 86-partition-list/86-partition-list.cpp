/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode*curr = head;
        
        ListNode*head1 = new ListNode(0);
        ListNode*head2 = new ListNode(0);
        
        ListNode*small = head1;
        ListNode*big = head2;
        
        while(curr != NULL){
            
            if(curr->val < x){
                small->next = curr;
                small = small->next;
            }
            else{
                big->next = curr;
                big = big->next;
            }
            
            curr = curr->next;
        }
        
        small->next = head2->next;
        big->next = NULL;
        
        return head1->next;
    }
};