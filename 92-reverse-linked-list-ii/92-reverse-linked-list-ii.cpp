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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode*front = head;
        ListNode*end = head;
        
        int count = 1;
        
        while(count < left-1){
            front = front->next;
            count++;
        }
        
        count = 1;
        
        while(count <= right){
            end = end->next;
            count++;
        }
        
        if(left==1){
            
            ListNode*curr = head;
            ListNode*prev = NULL, *next=NULL;

            while(curr != end){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            head->next = curr;
            
            return prev;
        }
        
        ListNode*curr = front->next;
        ListNode*p = front->next;
        ListNode*prev = NULL, *next=NULL;
        
        while(curr != end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        front->next = prev;
        p->next = end;
        
        return head;
    }
};