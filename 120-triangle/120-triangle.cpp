// TC : O(N^2)
// SC : O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() == 1) return triangle[0][0];
        
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    triangle[i][j] += triangle[i-1][j];
                }
                else if(j==triangle[i].size()-1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else{
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        
        int ans = INT_MAX;
        for(auto x : triangle[triangle.size()-1]){
            ans = min(ans, x);
        }
        
        return ans;
    }
};