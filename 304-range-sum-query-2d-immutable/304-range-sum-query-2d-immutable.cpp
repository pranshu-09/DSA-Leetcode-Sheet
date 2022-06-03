// TC : O(NxM) for constructor    O(N) for sumRegion
// SC : O(NxM)
class NumMatrix {
public:
    
    int dp[201][201];
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        memset(dp, 0, sizeof dp);
        
        for(int i=0;i<matrix.size();i++){
            dp[i][0] = matrix[i][0];
            for(int j=1;j<matrix[0].size();j++){
                dp[i][j] = dp[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        
        for(int i=row1;i<=row2;i++){
            if(col1==0){
                ans += (dp[i][col2]);
            }
            else{
                ans += (dp[i][col2] - dp[i][col1-1]);
            }
        }
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */