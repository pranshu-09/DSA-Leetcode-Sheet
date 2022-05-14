// Dijsktra's Algorithm

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>>adj;
        unordered_map<int, int>dist;
        
        for(int i=1;i<=n;i++){
            dist[i] = INT_MAX;
        }
        
        for(auto x : times){
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        set<pair<int, int>>s;
        s.insert({0, k});
        
        dist[k] = 0;
        
        while(!s.empty()){
            
            auto p = *(s.begin());
            
            int node = p.second;
            int dis = p.first;
            s.erase(s.begin());
            
            for(auto child : adj[node]){
                
                if(child.second + dis < dist[child.first]){
                    
                    auto f = s.find({dist[child.first], child.first});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    
                    dist[child.first] = child.second + dis;
                    s.insert({dist[child.first], child.first});
                }
            }
        }
        
        int max_time = 0;
        for(auto x : dist){
            if(x.second == INT_MAX) return -1;
            max_time = max(max_time, x.second);
        }
        
        return max_time;
    }
};