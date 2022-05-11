// TC : O(N)
// SC : O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i = n-2;
        
        // find  the element till which changes need to be made
        while(i>=0 and nums[i]>=nums[i+1]){
            i--;
        }
        
        
        // find the next greater element of the current element
        if(i>=0){
            int j = n-1;
            while(j>=0 and nums[i]>=nums[j]){
                j--;
            }
            
            // swap the 2 numbers
            swap(nums[i], nums[j]);
        }
        
        // reverse the rest of the numbers from i+1 to end
        reverse(nums.begin()+i+1, nums.end());
    }
};