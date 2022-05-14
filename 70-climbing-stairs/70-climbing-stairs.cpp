// TC : O(N)
// SC : O(1)
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1 or n==2){
            return n;
        }
        
        int a = 1;
        int b = 2;
        
        for(int i=3;i<=n;i++){
            int c = a+b;
            a = b;
            b = c;
        }
        
        return b;
    }
};


// TC : O(N)
// SC : O(N)

/*
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1 or n==2){
            return n;
        }
        
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
*/