// Boyer-Moore Voting Algorithm
// TC : O(N)
// SC : O(1)

class Solution {
public:
    
    /*
    bool is_majority(vector<int>&nums, int cand){
        
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == nums[cand]){
                cnt++;
            }
        }
        
        if(cnt > nums.size()/2){
            return true;
        }        
        
        return false;
    }
    */
    
    int majorityElement(vector<int>& nums) {
     
        int cand = 0;     // candidate for majority element
        int cnt = 0;      // count of majority element
        
        // Idea is that if we storing the cnt of candidate and its cnt will be greater than n/2, after traversing the complete array, its cnt will always be greater than 0.
        // Hence, in the  end, we will receive the majority element
        
        for(int i=0;i<nums.size();i++){
            
            // update candidate to nums[i] if count is 0
            if(cnt == 0){
                cand = nums[i];
            }
            
            // if same element found as candidate, increment cnt else dec cnt
            if(nums[i] == cand){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        /* if in the problem, it is not mentioned there will definitely be a majority element, then verify tha candidate
        if(is_majority(nums, cand)){
            return nums[cand];
        }
        */
        
        return cand;
    }
};