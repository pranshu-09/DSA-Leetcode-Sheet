// TC : O(N2)
// SC : O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        int n = nums.size();
        vector<vector<int>>ans;
        
        if(n<=2){
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            int l = i+1, r = n-1;
            int term1 = nums[i];
            
            while(l<r){
                
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    int term2 = nums[l];
                    int term3 = nums[r];
                    
                    while(l<r and nums[l]==term2)
                        l++;
                    
                    while(l<r and nums[r]==term3)
                        r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }
                else{
                    r--;
                }              
            }
            
            while(i<n-1 and nums[i]==nums[i+1]){
                i++;
            }
        }
        
        return ans;
    }
};