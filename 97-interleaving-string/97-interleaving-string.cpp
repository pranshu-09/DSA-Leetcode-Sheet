class Solution {
public:
    
    // int dp[101][101][201];
    
//     bool is_inter(string&s1, string&s2, string&s3, int i, int j, int k){
        
//         if(k==s3.size()){
//             if(i==s1.size() and j==s2.size()){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
        
//         if(i==s1.size()){
//             if(s2.substr(j) == s3.substr(k)){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
        
        
//         if(j==s2.size()){
//             if(s1.substr(i) == s3.substr(k)){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
        
//         if(dp[i][j][k] != -1){
//             return dp[i][j][k];
//         }
        
//         if(s1[i]==s3[k] and s2[j]==s3[k]){
//             return dp[i][j][k] = is_inter(s1, s2, s3, i+1, j, k+1) or is_inter(s1, s2, s3, i, j+1, k+1);
//         }
//         else if(s1[i]==s3[k]){
//             return dp[i][j][k] = is_inter(s1, s2, s3, i+1, j, k+1);
//         }
//         else if(s2[j]==s3[k]){
//             return dp[i][j][k] = is_inter(s1, s2, s3, i, j+1, k+1);
//         }
//         else{
//             return dp[i][j][k] = false;
//         }
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        
        bool dp[101][101];
        
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        
        // When i == 0
        for(int j=1;j<=s2.size();j++){
            if(s2[j-1]==s3[j-1]){
                dp[0][j] = dp[0][j-1];
            }
            else{
                dp[0][j] = false;
            }
        }
        
        for(int i=1;i<=s1.size();i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }
            else{
                dp[i][0] = false;
            }
        }
        
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                    
                if(s1[i-1]==s3[i+j-1] and s2[j-1]==s3[i+j-1]){
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else if(s1[i-1]==s3[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(s2[j-1]==s3[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};