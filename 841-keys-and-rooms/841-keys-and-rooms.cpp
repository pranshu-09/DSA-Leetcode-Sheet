class Solution {
public:
    
    void open_rooms(vector<vector<int>>& rooms, int src, vector<bool>&vis){
        
        vis[src] = true;
        
        for(auto nbr : rooms[src]){
            if(!vis[nbr]){
                open_rooms(rooms, nbr, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<bool>vis(n, false);
        
        open_rooms(rooms, 0, vis);
        
        for(auto x : vis){
            if(x == false){
                return false;
            }
        }
        
        return true;
    }
};