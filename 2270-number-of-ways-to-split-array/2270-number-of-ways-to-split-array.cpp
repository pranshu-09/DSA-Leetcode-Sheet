class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        long long int rsum = 0;
        for(auto x : nums) rsum += x;
        
        long long int lsum=0;
        int cnt = 0;
        
        for(int i=0;i<n-1;i++){
            lsum += nums[i];
            
            if(lsum >= (rsum-lsum)){
                cnt++;
            }
        }
        
        return cnt;
    }
};