// TC : O(SxMxN)
// SC : O(SxMxN)

class Solution {
public:
    
    int dp[601][101][101];
    
    int find_cnt(string s, char ch){
        int cnt = 0;
        for(auto x : s){
            if(ch == x) cnt++;
        }
        
        return cnt;
    }
    
    int find_len(vector<string>& strs, int i, int m, int n){
        
        if(i==strs.size() or m<0 or n<0){
            return 0;
        }
        
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        
        int one = find_cnt(strs[i], '1');
        int zero = find_cnt(strs[i], '0');
        
        if(m-zero>=0 and n-one>=0){
            int inc = find_len(strs, i+1, m-zero, n-one) + 1;
            int exc = find_len(strs, i+1, m, n);
            
            return dp[i][m][n] = max(inc, exc);
        }
        else{
            return dp[i][m][n] = find_len(strs, i+1, m, n);
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp, -1, sizeof dp);
        
        return find_len(strs, 0, m, n);        
    }
};

// Recursion
/*
class Solution {
public:
    
    vector<int>zero;
    vector<int>one;
    
    int find_len(vector<string>& strs, int i, int m, int n){
        
        if(i==strs.size() or m<0 or n<0){
            return 0;
        }
        
        if(m-zero[i]>=0 and n-one[i]>=0){
            int inc = find_len(strs, i+1, m-zero[i], n-one[i]) + 1;
            int exc = find_len(strs, i+1, m, n);
            
            return max(inc, exc);
        }
        else{
            return find_len(strs, i+1, m, n);
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        zero.resize(strs.size(), 0);
        one.resize(strs.size(), 0);
        
        for(int i=0;i<strs.size();i++){
            for(auto x : strs[i]){
                if(x=='0') zero[i]++;
                else one[i]++;
            }
        }
        
        return find_len(strs, 0, m, n);        
    }
};
*/    