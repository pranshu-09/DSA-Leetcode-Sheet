// TC : O(Nx<)
// SC : O(Nx<)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans(matrix[0].size(), vector<int>(matrix.size()));
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<matrix.size();j++){
                ans[i][j] = matrix[j][i];
            }
        }
        
        return ans;
    }
};