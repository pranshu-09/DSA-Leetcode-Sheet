// TC : O(NXsum)
// SC : O(sum)

class Solution {
public:
    
    int coinChange(vector<int>&arr, int sum) {
        
        int n = arr.size();
        
        // dp stores the minimum number of coins required to get particular sum
        vector<int>dp(sum+1, sum+1);
        
        dp[0] = 0;
        
        for(int i=1;i<=sum;i++){
            for(int j=0;j<n;j++){
                if(i-arr[j]>=0)
                    dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
        
        if(dp[sum] == sum+1) return -1;
        
        return dp[sum];
    }
};

// Recursion
/*
class Solution {
public:
    
    int find_coins(vector<int>&arr, long long int sum, int target, int i){
        
        if(i==arr.size() or sum>target){
            return INT_MAX;
        }
        
        if(sum == target){
            return 0;
        }
        
        if(sum+arr[i] <= target){
            int inc = find_coins(arr, sum+arr[i], target, i);
            int exc = find_coins(arr, sum, target, i+1);
            
            if(inc==INT_MAX and exc==INT_MAX) return INT_MAX;
            
            if(inc < exc){
                return inc+1;
            }
            else{
                return exc;
            }
        }
        else{
            int exc = find_coins(arr, sum, target, i+1);
            return exc==INT_MAX ? INT_MAX : exc;
        }
    }
    
    int coinChange(vector<int>&arr, int sum) {
        
        int ans = find_coins(arr, 0, sum, 0);        
        
        return ans==INT_MAX ? -1 : ans;
    }
};
*/