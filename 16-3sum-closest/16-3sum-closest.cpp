// TC : O(N^2)
// SC : O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int min_dif = INT_MAX;
        int ans = 0;
        
        for(int i=0;i<n-2;i++){
            
            int j=i+1, k=n-1;
            
            while(j < k){
                
                int sum = nums[i] + nums[j] + nums[k];
                int dif = abs(target - sum);
                
                // The exact sum will be the closest to target (they are equal). Hence, no need to check further. Directly return sum.
                if(sum == target){
                    return sum;
                }
                
                if(dif < min_dif){
                    min_dif = dif;
                    ans = sum;
                }
                
                if(sum < target){
                    j++;
                }
                else{
                    k--;
                } 
            }
        }
        
        return ans;
        
    }
};