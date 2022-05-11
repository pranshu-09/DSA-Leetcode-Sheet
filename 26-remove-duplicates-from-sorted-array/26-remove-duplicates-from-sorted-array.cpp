// TC : O(N)
// SC : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int idx = 0;
        int n = nums.size();
        
        for(int i=0;i<n;){
            if(nums[i] != nums[idx]){
                nums[++idx] = nums[i];
            }
            i++;
        }
        
        return idx+1;
    }
};