class Solution {
public:
    
    unordered_map<int, list<int>>adj;
    
    void open_rooms(int src, vector<bool>&vis){
        
        vis[src] = true;
        
        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                open_rooms(nbr, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        adj.clear();
        
        for(int i=0;i<n;i++){
            for(auto x : rooms[i]){
                adj[i].push_back(x);
            }
        }
        
        vector<bool>vis(n, false);
        
        open_rooms(0, vis);
        
        for(auto x : vis){
            if(x == false){
                return false;
            }
        }
        
        return true;
    }
};