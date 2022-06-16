// Topological Sorting check problem => topological sorting can only be applied on an acyclic directed graph. If there is a cycle present, courses cannot be scheduled.
class Solution {
public:
    
    bool cycle_present(unordered_map<int, list<int>>&adj, int src, vector<bool>&vis, vector<bool>&st){
        
        vis[src] = true;
        st[src] = true;
        
        for(auto nbr : adj[src]){
            if(vis[nbr] == true and st[nbr] == true){
                return true;
            }
            else if(vis[nbr] == false){
                
                bool check = cycle_present(adj, nbr, vis, st);
                
                if(check)
                    return true;
            }
        }
        
        st[src] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool>vis(numCourses, false);
        vector<bool>st(numCourses, false);
        
        unordered_map<int, list<int>>adj;
        
        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                bool check = cycle_present(adj, i, vis, st);
                
                if(check)           // if cycle present => course can't be scheduled
                    return false;
            }
        }
        
        return true;
    }
};