class Solution {
public:
    
    bool check_bipartite(vector<vector<int>>& graph, int src, int col, vector<int>&colors){
        
        if(colors[src] != -1){
            if(colors[src] != col){
                return false;
            }
            return true;
        }
        
        colors[src] = col;
        
        for(auto x : graph[src]){            
            if(check_bipartite(graph, x, abs(1-col), colors)==false)
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>colors(graph.size(), -1);
        
        for(int i=0;i<graph.size();i++){
            if(colors[i] == -1){
                if(check_bipartite(graph, i, 1, colors)==false)
                    return false;
            }
        }
        
        return true;
    }
};