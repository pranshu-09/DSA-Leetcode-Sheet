// TC : O(logN)
// SC : O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(!binary_search(nums.begin(), nums.end(), target)) 
            return {-1, -1};
        
        int low = -1, high = -1;
        
        int s = 0, e = nums.size()-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] >= target){
                low = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        s = 0, e = nums.size()-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] <= target){
                high = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return {low, high};
    }
};