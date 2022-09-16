class Solution {
public:
    int dp[1001][1001];

    int max_score(vector<int> &nums, vector<int> &multi, int i, int l, int r){

        if(i==multi.size()){
            return 0;
        }
        
        if(dp[l][i] != INT_MIN){
            return dp[l][i];
        }

        int first = multi[i]*nums[l] + max_score(nums, multi, i+1, l+1, r);
        int last = multi[i]*nums[r] + max_score(nums, multi, i+1, l, r-1);

        return dp[l][i] = max(first, last);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {

        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j] = INT_MIN;
            }
        }

        return max_score(nums, multi, 0, 0, nums.size()-1);
    }
};