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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL){
            return NULL;
        }
        
        stack<ListNode*> st;
        ListNode*temp = head;
        
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }
        
        ListNode*temp2 = NULL;
        while(n--){
            temp2 = st.top();
            st.pop();
        }
        
        if(st.empty()){
            return head->next;
        }
        
        st.top()->next = temp2->next;
        
        return head;
    }
};