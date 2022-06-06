/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TC : O(N+M)
// SC : O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode*p1 = headA;
        ListNode*p2 = headB;
        
        while(p1!=NULL and p2!=NULL and p1!=p2){
            
            p1 = p1->next;
            p2 = p2->next;
            
            if(p1 == p2){
                return p1;
            }
            
            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
            
            if(p1 == NULL){
                p1 = headB;
            }
            
            if(p2 == NULL){
                p2 = headA;
            }
        }
        
        return p1;
    }
};