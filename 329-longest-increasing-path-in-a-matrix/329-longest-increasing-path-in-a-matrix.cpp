// TC : O(NxM)
// SC : O(NxM)

class Solution {
public:
    
    int n, m;
    int dp[201][201];
    
    bool is_valid(vector<vector<int>>& matrix, int i, int j){
        if(i<0 or i>=n or j<0 or j>=m){
            return false;
        }
        
        return true;
    }
    
    int find_path(vector<vector<int>>& matrix, int i, int j){
        
        if(!is_valid(matrix, i, j)){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 0;
        int op1=0, op2=0, op3=0, op4=0;
        
        if(is_valid(matrix, i-1, j) and matrix[i-1][j]>matrix[i][j]){
            op1 = find_path(matrix, i-1, j);
        }
        
        if(is_valid(matrix, i+1, j) and matrix[i+1][j]>matrix[i][j]){
            op2 = find_path(matrix, i+1, j);
        }
        
        if(is_valid(matrix, i, j-1) and matrix[i][j-1]>matrix[i][j]){
            op3 = find_path(matrix, i, j-1);
        }
        
        if(is_valid(matrix, i, j+1) and matrix[i][j+1]>matrix[i][j]){
            op4 = find_path(matrix, i, j+1);
        }
        
        ans = max({op1, op2, op3, op4}) + 1;
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     
        n = matrix.size();
        m = matrix[0].size();
        
        memset(dp, -1, sizeof dp);
        
        int ans = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                    ans = max(ans, find_path(matrix, i, j));
                }
            }
        }
        
        return ans;
    }
};