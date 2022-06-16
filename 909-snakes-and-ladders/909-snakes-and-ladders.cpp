// TC : O(N^2)
class Solution {
    
    unordered_map<int, list<int>>bd;
    
public:
    
    void add(int x, int y){
        bd[x].push_back(y);
    }
    
    int sssp(int src, int dst){
        
        queue<int>q;
        unordered_map<int, int>dist;
        
        for(auto x : bd){
            dist[x.first] = INT_MAX;
        }
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            
            int f = q.front();
            q.pop();
            
            for(auto nbr : bd[f]){
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[f] + 1;
                }
            }
        }

        return dist[dst];
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int board_temp[500] = {0};
        int n = board.size();
        int dir = 1;
        
        int count = 1;
        
        for(int i=n-1;i>=0;i--){
            
            if(dir == 1){
                for(int j=0;j<board[i].size();j++){

                    if(board[i][j] != -1){
                        board_temp[count] = board[i][j] - count;
                    }
                    count++;
                }
                dir = -1;
            }
            else{
                for(int j=board[i].size()-1;j>=0;j--){

                    if(board[i][j] != -1){
                        board_temp[count] = board[i][j] - count;
                    }
                    count++;
                }
                dir = 1;
            }
        }
        
        // add edges for the board
        for(int i=1;i<n*n;i++){
            for(int dc=1;dc<=6;dc++){
                
                int j = i + dc;
                j += board_temp[j];
                
                if(j<=n*n){
                    add(i, j);
                }                
            }            
        }
        add(n*n, n*n);
        
        int short_path = sssp(1, n*n);
        
        return short_path == INT_MAX ? -1 : short_path;
    }
};