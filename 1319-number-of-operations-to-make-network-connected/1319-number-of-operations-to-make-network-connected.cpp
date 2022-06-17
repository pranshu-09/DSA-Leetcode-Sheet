class Solution {
public:
    
    unordered_map<int, list<int>>adj;
    
    void connected_component(int src, int&edges, int&vertices, vector<bool>&vis){
        
        vis[src] = true;
        vertices++;
        
        for(auto nbr : adj[src]){
            edges++;
            if(!vis[nbr]){
                connected_component(nbr, edges, vertices, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        adj.clear();
        
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<bool>vis(n, false);
        
        int comp = 0;   // find all components 
        int surp = 0;   // find surplus edges
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                int ed = 0, vt = 0;
                connected_component(i, ed, vt, vis);
                
                surp += (ed/2 - (vt-1));
                comp++;
            }
        }
        
        if(surp < comp-1){
            return -1;
        }
        
        return comp-1;
    }
};