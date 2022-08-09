#define mod 1000000007

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        long long ans =0;
        unordered_map<long long, long long> up;
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i< arr.size(); i++){
            long long cur = 1;
            for(int j=0; j<i; j++){
                
                if(arr[i]%arr[j]) 
                    continue;
                
                int ans1 = arr[i]/arr[j];
                int ans2 = arr[j];
                cur = (cur + up[ans1]*up[ans2]%mod)%mod;
            }
            up[arr[i]] = cur;
            ans += cur;
        }
        
        return ans%mod;
    }
};