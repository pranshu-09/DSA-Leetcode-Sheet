// Memoization
class Solution {
public:
    
    int dp[101][101][21];
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int idx, int target, int last_col, int n){
        
        if(target < 0){
            return INT_MAX;
        }
        
        if(idx == houses.size()){
            return target==0 ? 0 : INT_MAX;
        }
        
        if(dp[idx][target][last_col] != -1){
            return dp[idx][target][last_col];
        }
        
        if(houses[idx] != 0){
            if(last_col != houses[idx]){
                target--;
            }
            
            return dfs(houses, cost, idx+1, target, houses[idx], n);
        }
        
        int ans = INT_MAX;
        for(int color=1;color<=n;color++){
            
            int rest = dfs(houses, cost, idx+1, target - ((last_col==color) ? 0 : 1), color, n);
            
            if(rest!=INT_MAX){
                ans = min(ans, cost[idx][color-1] + rest);
            }
        }
        
        return dp[idx][target][last_col] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp, -1, sizeof dp);
        
        int ans = dfs(houses, cost, 0, target, 0, n);
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};

// Recursion
/*
class Solution {
public:
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int idx, int target, int last_col, int n){
        
        if(target < 0){
            return INT_MAX;
        }
        
        if(idx == houses.size()){
            return target==0 ? 0 : INT_MAX;
        }
        
        if(houses[idx] != 0){
            if(last_col != houses[idx]){
                target--;
            }
            
            return dfs(houses, cost, idx+1, target, houses[idx], n);
        }
        
        int ans = INT_MAX;
        for(int color=1;color<=n;color++){
            
            int rest = dfs(houses, cost, idx+1, target - ((last_col==color) ? 0 : 1), color, n);
            
            if(rest!=INT_MAX){
                ans = min(ans, cost[idx][color-1] + rest);
            }
        }
        
        return ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        int ans = dfs(houses, cost, 0, target, 0, n);
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};
*/