#define mod 1000000007

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> ess(n);
        
        for (int i=0; i<n; i++){
            ess[i] = {efficiency[i], speed[i]};
        }
        
        sort(rbegin(ess), rend(ess));
        
        long sumS = 0, ans = 0;
        
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(auto x : ess){
            pq.push(x.second);
            sumS += x.second;
            
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, sumS*x.first);
        }
        
        return ans % mod;
    }
};