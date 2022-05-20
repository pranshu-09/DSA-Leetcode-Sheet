// Memoization
// TC : O(N^2)
// SC : O(N^2)

class Solution {
public:
    
    unordered_set<string>s;
    int dp[301][301];
    
    bool check_sen(string sen, int i, int j){
        
        if(i==sen.size()){
            return true;
        }
        
        if(j==sen.size()-1){
            string x = sen.substr(i, j-i+1);
            if(s.find(x) != s.end()){
                return true;
            }
            
            return false;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        string x = sen.substr(i, j-i+1);
        
        if((s.find(x) != s.end()) and check_sen(sen, j+1, j+1)){
            return dp[i][j] = true;
        }
        else{
            return dp[i][j] = check_sen(sen, i, j+1);
        }       
    }
    
    bool wordBreak(string sen, vector<string>& wordDict) {
        
        for(auto x : wordDict){
            s.insert(x);
        }
        
        memset(dp, -1, sizeof dp);
        
        return check_sen(sen, 0, 0);
    }
};

// Recursion Solution
/*
class Solution {
public:
    
    unordered_set<string>s;
    
    bool check_sen(string sen, int i, int j){
        
        if(i==sen.size()){
            return true;
        }
        
        if(j==sen.size()-1){
            string x = sen.substr(i, j-i+1);
            if(s.find(x) != s.end()){
                return true;
            }
            
            return false;
        }
        
        string x = sen.substr(i, j-i+1);
        
        if((s.find(x) != s.end()) and check_sen(sen, j+1, j+1)){
            return true;
        }
        else{
            return check_sen(sen, i, j+1);
        }       
    }
    
    bool wordBreak(string sen, vector<string>& wordDict) {
        
        for(auto x : wordDict){
            s.insert(x);
        }
        
        return check_sen(sen, 0, 0);
    }
};
*/