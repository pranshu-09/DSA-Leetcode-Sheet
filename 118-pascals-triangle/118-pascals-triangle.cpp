// TC : O(N^2)
// SC : O(1)

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        if(n==1){
            return {{1}};
        }
        
        vector<vector<int>>ans(n);
        
        ans[0] = {1};
        ans[1] = {1,1};
        
        for(int i=2;i<n;i++){
            vector<int>temp(i+1, 1);
            ans[i] = temp;
        }
        
        for(int i=2;i<n;i++){
            for(int j=1;j<=i-1;j++){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        
        return ans;
    }
};