class Solution {
public:
    
    void dfs(vector<vector<int>>&adj, vector<int>&low, vector<int>&par, vector<int>&disc, vector<vector<int>>&ans, int u){
        
        static int time = 0;
        
        disc[u] = low[u] = time;
        time += 1;
        
        for(auto v : adj[u]){
            if(disc[v]==-1){
                par[v] = u;
                dfs(adj, low, par, disc, ans, v);
                low[u] = min(low[u], low[v]);
                
                if(low[v] > disc[u]){
                    ans.push_back({u, v});
                }
            }
            else if(v != par[u]){
                low[u] = min(low[u], low[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);
        
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<vector<int>>ans;
        
        vector<int>low(n, -1);
        vector<int>par(n, -1);
        vector<int>disc(n, -1);
        
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(adj, low, par, disc, ans, i);
            }
        }
        
        return ans;
    }
};

/*
class Solution {
public:
    
    void find_components(unordered_map<int, unordered_set<int>>&adj, vector<bool>&vis, int src){
        
        if(vis[src]){
            return;
        }
        
        vis[src] = true;
        
        for(auto x : adj[src]){
            find_components(adj, vis, x);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_map<int, unordered_set<int>>adj;
        
        for(auto x : connections){
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        
        vector<vector<int>>ans;
        
        for(auto x : connections){
            
            int a = x[0];
            int b = x[1];
            
            adj[a].erase(b);
            adj[b].erase(a);
            
            vector<bool>vis(n, false);
            
            int con = 0;    // count number of components
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    find_components(adj, vis, i);
                    con++;
                    
                    if(con > 1){
                        ans.push_back({a, b});
                        break;
                    }
                }
            }
            
            adj[a].insert(b);
            adj[b].insert(a);            
        }
        
        return ans;
    }
};
*/