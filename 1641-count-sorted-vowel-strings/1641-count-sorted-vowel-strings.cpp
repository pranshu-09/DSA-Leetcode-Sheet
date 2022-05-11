// TC : O(N)
// SC : O(1)
// DP Approach

class Solution {
public:
    
    int countVowelStrings(int n) {
        
        vector<int>dp(5, 1);
        
        for(int i=2;i<=n;i++){
            
            // Start updating from right to left
            // Value for string starting with 'u' will always be 1 for lexicographically sorted ans
            for(int j=3;j>=0;j--){
                // dp[i] = old dp[i] value + new updated dp[i+1] value
                dp[j] = dp[j] + dp[j+1];
            }
        }
        
        int ans = 0;
        for(auto x : dp){
            ans += x;
        }
        
        return ans;
    }
};


// Recursive Apprach
// class Solution {
// public:
    
//     vector<char>vow{'a','e','i','o','u'};
    
//     int count_vowel(int n, char ch){
        
//         if(n==0){
//             return 1;
//         }
        
//         int ans = 0;
        
//         for(int i=0;i<5;i++){
//             if(ch <= vow[i]){
//                 ans += count_vowel(n-1, vow[i]);
//             }
//         }
        
//         return ans;
//     }
    
//     int countVowelStrings(int n) {
//         return count_vowel(n,'a');
//     }
// };