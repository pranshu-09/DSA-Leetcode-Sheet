class Solution {
public:
    
    vector<vector<int>>ans;
    
    void find_paths(vector<vector<int>>& graph, int src, vector<int>cur){
        
        if(src == graph.size()-1){
            cur.push_back(src);
            ans.push_back(cur);
            return;
        }
        
        cur.push_back(src);
        for(auto x : graph[src]){
            find_paths(graph, x, cur);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        ans.clear();
        
        find_paths(graph, 0, {});
        
        return ans;
    }
};