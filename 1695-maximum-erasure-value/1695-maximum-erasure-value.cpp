// TC : O(N)
// SC : O(N)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        unordered_set<int>s;
        
        int i=0, j=0;
        int sum = 0;
        int max_sum = 0;
        
        while(j < nums.size()){
            
            if(s.find(nums[j]) != s.end()){
                
                while(i<j and nums[i]!=nums[j]){
                    max_sum = max(max_sum, sum);
                    sum -= nums[i];
                    s.erase(nums[i]);
                    i++;
                }
                
                i++;
                j++;
            }
            else{
                s.insert(nums[j]);
                sum += nums[j];
                j++;
            }
        }
        
        max_sum = max(max_sum, sum);
        return max_sum;
    }
};