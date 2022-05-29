// TC : O(2^N)

class Solution {
public:
    
    vector<string>ans;
    
    void generate(int n, int open, int close, string cur){
        
        if(close == n){
            ans.push_back(cur);
            return;
        }
        
        if(open < n){
            generate(n, open+1, close, cur+'(');
        }
        
        if(open > close){
            generate(n, open, close+1, cur+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        ans.clear();
        generate(n, 0, 0, "");
        
        return ans;
    }
};