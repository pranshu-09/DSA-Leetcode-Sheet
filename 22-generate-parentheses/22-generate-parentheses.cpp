class Solution {
public:
    
    void generate(int n, vector<string>&ans, string curr, int ob, int cb){
        
        if(cb==n){
            ans.push_back(curr);
            return;
        }
        
        if(ob < n){
            generate(n, ans, curr+'(', ob+1, cb);
        }
        if(ob > cb){
            generate(n, ans, curr+')', ob, cb+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        
        generate(n, ans, "", 0, 0);
        
        return ans;
    }
};