// TC : O(N)
// SC : O(N)

class Solution {
public:
    
    int longestValidParentheses(string s) {
     
        if(s.size()==0){
            return 0;
        }
        
        stack<char>cs;
        stack<int>idx;
        
        idx.push(-1);
        
        int max_len = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){
                cs.push(s[i]);
                idx.push(i);
            }
            else{
                
                if(cs.empty()){
                    idx.push(i);
                }
                else{
                    cs.pop();
                    idx.pop();
                    max_len = max(max_len, i-idx.top());
                }
            }
        }
        
        return max_len;
    }
};