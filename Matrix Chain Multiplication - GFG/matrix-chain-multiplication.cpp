// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        n--;
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for(int gap=0;gap<n;gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                
                if(gap==0){
                    dp[i][j] = 0;
                }
                else if(gap==1){
                    dp[i][j] = arr[i] * arr[i+1] * arr[j+1];
                }
                else{
                    int val = INT_MAX;
                    for(int k=i;k<j;k++){
                        int left = dp[i][k];
                        int right = dp[k+1][j];
                        
                        int mul = arr[i] * arr[k+1] * arr[j+1];
                        
                        val = min(val, mul + left + right);
                    }
                    dp[i][j] = val;
                }
            }
        }
        
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends