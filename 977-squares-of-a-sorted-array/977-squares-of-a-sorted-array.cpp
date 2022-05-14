// TC : O(N)
// SC : O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        // find index of first positive integer or 0
        int zero;
        
        if(nums[0]>=0){
            zero = 0;
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]>=0){
                    zero = i;
                    break;
                }
            }
        }
        
        int i=zero-1;
        int j=zero;
        
        vector<int>ans;
        
        while(i>=0 and j<n){
            if(abs(nums[i]) < abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        
        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        
        while(j<n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        
        return ans;
    }
};