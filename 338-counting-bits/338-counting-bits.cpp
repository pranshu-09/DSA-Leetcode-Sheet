// TC : O(num)
// SC : O(num)

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int>ans(num+1, 0);
        
        if(num==0){
            return ans;
        }
        
        for(int i=1;i<=num;i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        
        return ans;
    }
};