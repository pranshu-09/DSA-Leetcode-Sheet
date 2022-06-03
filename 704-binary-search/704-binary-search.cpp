// TC : O(logN)
// SC : O(1)
class Solution {
public:
    
    int bs(vector<int>& nums, int target, int s, int e){
        
        if(s > e){
            return -1;
        }
        
        int m = s + (e - s) / 2;
        
        if(target == nums[m]){
            return m;
        }
        else if(target > nums[m]){
            return bs(nums, target, m+1, e);
        }
        return bs(nums, target, s, m-1);
    }
    
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size()-1);  
    }
};