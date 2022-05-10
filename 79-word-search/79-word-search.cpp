class Solution {
public:
    
    bool check(vector<vector<char>>& board, int i, int j, int n, int m, int idx, string&word, vector<vector<bool>>&vis){
        
        if(idx == word.size()){
            return true;
        }
        
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or board[i][j]!=word[idx]){
            return false;
        }
        
        vis[i][j] = true;
        
        if(board[i][j]==word[idx]){
            bool up = check(board, i-1, j, n, m, idx+1, word, vis);
            bool left = check(board, i, j-1, n, m, idx+1, word, vis);
            bool down = check(board, i+1, j, n, m, idx+1, word, vis);
            bool right = check(board, i, j+1, n, m, idx+1, word, vis);
            
            if(left or right or up or down){
                return true;
            }
        }
        
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>>vis(n, vector<bool>(m, false));
                    
                    if(check(board, i, j, n, m, 0, word, vis)){
                        return true;
                    }
                }
            }
        }
        
        return false;        
    }
};