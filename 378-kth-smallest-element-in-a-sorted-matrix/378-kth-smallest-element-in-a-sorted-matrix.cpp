class Solution {
public:
    
    typedef pair<int, pair<int, int> > custom_pair;
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<custom_pair, vector<custom_pair>, greater<custom_pair> > pq;
        
        bool visited[matrix.size()][matrix[0].size()];
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                visited[i][j] = false;
            }
        }
        
        // for(int i=0;i<matrix[0].size();i++){
            pq.push({matrix[0][0], {0, 0}});
            visited[0][0] = true;
        // }
        
        int ans = 0;
        
        for(int i=0;i<k;i++){
            
            custom_pair p = pq.top();
            pq.pop();
            
            ans = p.first;
            
            int x = p.second.first;
            int y = p.second.second;
            
            if(y+1 < matrix[x].size() and !visited[x][y+1]){
                pq.push({matrix[x][y+1], {x, y+1}});
                visited[x][y+1] = true;
            }
            
            if(x+1 < matrix.size() and !visited[x+1][y]){
                pq.push({matrix[x+1][y], {x+1, y}});
                visited[x+1][y] = true;
            }            
        }
        
        return ans;        
    }
};