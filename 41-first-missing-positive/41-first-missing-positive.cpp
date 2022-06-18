// TC : O(N)
// SC : O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        nums.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            
            int x = nums[i];
            
            while(x>=0 and x<nums.size() and x!=nums[x]){
                swap(x, nums[x]);
            }
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] != i){
                return i;
            }
        }
        
        return nums.size();
    }
};