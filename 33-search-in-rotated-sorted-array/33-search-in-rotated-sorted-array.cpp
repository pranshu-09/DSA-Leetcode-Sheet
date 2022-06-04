// TC : O(logN)
// SC : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size()-1;
        
        while(s <= e){
            
            int mid = (s + e) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            // to check if mid point lies in region1
            if(nums[s] <= nums[mid]){
                
                // if nums[s] <= target <= nums[mid] => target is in [s, mid]
                if(nums[s]<=target and target<=nums[mid]){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            else{
                // if nums[mid] <= target <= nums[e] => target is in [mid, e]
                if(nums[mid]<=target and target<=nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
        
        return -1;
    }
};