// TC : O(N^2)
// SC : O(1)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans(matrix[0].size());
        
        for(int i=0;i<ans.size();i++){
            vector<int>m;
            for(int j=0;j<matrix.size();j++){
                m.push_back(matrix[j][i]);
            }
            ans[i] = m;
        }
        
        return ans;
    }
};