class Solution {
public:
    
    vector<string>keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string>ans;
    
    void find_comb(string s, int i, string cur){
        
        if(i == s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(auto x : keypad[s[i]-'0']){
            find_comb(s, i+1, cur+x);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0){
            return {};
        }
        
        ans.clear();
        
        find_comb(digits, 0, "");
        
        return ans;
    }
};