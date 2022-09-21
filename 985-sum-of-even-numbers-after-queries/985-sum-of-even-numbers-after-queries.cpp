class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum=0, n=queries.size();
        
        for (auto x : nums){
            if (!(x&1)){
                sum += x;
            }
        }
        
        vector<int> ans(n, 0);

        for (int i=0; i<n; i++){
            
            int val = queries[i][0], idx = queries[i][1];
            int old_val = nums[idx];
            nums[idx] += val;
            
            bool even = (old_val % 2) == 0;
            bool even_upd = (nums[idx] % 2 == 0);
            
            if(even && even_upd){
                sum += val;
                ans[i] = sum;
            } 
            else if(!even && even_upd){
                sum += nums[idx];
                ans[i] = sum;
            } 
            else if(even && !even_upd){
                sum -= old_val;
                ans[i] = sum;
            }
            else {
                ans[i] = sum;
            }
        }
        
        return ans;
    }
};