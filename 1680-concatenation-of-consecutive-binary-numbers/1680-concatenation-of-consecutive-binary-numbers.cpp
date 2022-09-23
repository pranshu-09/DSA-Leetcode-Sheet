#define mod 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        
        long long int ans = 0;
        int sz = 0;
        
        for (int i=1; i<=n; i++) {
            if ((i&(i-1)) == 0) {
                sz++;
            }
            ans = ((ans<<sz) + i) % mod;
        }
        
        return ans;
    }
};