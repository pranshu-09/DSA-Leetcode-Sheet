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

typedef pair<int, ListNode*> pp;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pp, vector<pp>, greater<pp> > pq;
        
        ListNode*head = new ListNode(0);
        ListNode*res = head;
        
        for(auto x : lists){
            if(x != NULL){
                pq.push({x->val, x});
            }
        }
        
        while(!pq.empty()){
            
            pp top = pq.top();
            pq.pop();
            
            int val = top.first;
            ListNode*cur_node = top.second;
            // ListNode*cur_list = top.second.second;
            
            res->next = cur_node;
            res = res->next;
            
            if(cur_node->next != NULL){
                pq.push({cur_node->next->val, cur_node->next});
            }
        }
        
        return head->next;
    }
};