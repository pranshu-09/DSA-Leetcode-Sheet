class Solution {
public:
    
    unordered_map<char, string>keypad;
    
    vector<string>ans;
    
    void find_comb(string s, int i, string cur){
        
        if(i == s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(auto x : keypad[s[i]]){
            find_comb(s, i+1, cur+x);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0){
            return {};
        }
        ans.clear();
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
        
        find_comb(digits, 0, "");
        
        return ans;
    }
};