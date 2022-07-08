// TC : O(NlogN)
// SC : O(N)
typedef pair<int, pair<int, int>> pp;

class Solution {
public:
    
    int dis(int x, int y){
        return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        for(auto x : points){
            pq.push({dis(x[0], x[1]), {x[0], x[1]}});
        }
        
        vector<vector<int>>ans;
        
        while(!pq.empty() and k--){
            pp t = pq.top();
            pq.pop();
            
            ans.push_back({t.second.first, t.second.second});
        }
        
        return ans;        
    }
};