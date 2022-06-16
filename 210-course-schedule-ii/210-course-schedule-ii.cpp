class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>ans;
        
        unordered_map<int, list<int>>adj;
        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int>indegree(numCourses, 0);
        
        for(int i=0;i<numCourses;i++){
            for(auto x : adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int f = q.front();
            q.pop();
            
            ans.push_back(f);
            
            for(auto nbr : adj[f]){
                indegree[nbr]--;
                
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }  
        }
        
        if(ans.size() != numCourses){
            return {};
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};