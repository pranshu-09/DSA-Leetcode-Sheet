// TC : O(N)
// SC : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int idx = 1;
        int n = nums.size();
        
        for(int i=1;i<n;){
            if(nums[i] == nums[i-1]){
                int k=i;
                while(k<n and nums[k] == nums[i-1]){
                    k++;
                }
                
                if(k != n){                     // if k==n, then don't do anything
                    nums[idx++] = nums[k];   
                }
                i = k+1;
            }
            else{
                nums[idx++] = nums[i];
                i++;
            }
        }
        
        return idx;
    }
};