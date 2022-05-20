// 1D DP Solution
// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    
    bool wordBreak(string sen, vector<string>& wordDict) {
        
        unordered_set<string>s;
        int n = sen.size();
        
        for(auto x : wordDict){
            s.insert(x);
        }
        
        vector<bool>dp(n+1, false);
        
        dp[0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                
                string x = sen.substr(j, ((i-1)-j+1));
                if(s.find(x) != s.end()){
                    if(dp[j] == true){
                        dp[i] = true;
                        break;          // we are sure that for current value of i, it is possible to break the string into words. Hence, no need to check further for other j
                    }
                }
            }
        }
        
        return dp[n];
    }
};

// Memoization
// TC : O(N^2)
// SC : O(N^2)
/*
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
*/

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