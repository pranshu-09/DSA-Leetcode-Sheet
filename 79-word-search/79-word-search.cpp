class Solution {
public:
    
    bool check(vector<vector<char>>& board, int i, int j, int n, int m, int idx, string&word){
        
        if(idx == word.size()){
            return true;
        }
        
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[idx] or board[i][j]=='_'){
            return false;
        }
        
        char ch = board[i][j];        
        board[i][j] = '_';
        
        bool up = check(board, i-1, j, n, m, idx+1, word);
        bool left = check(board, i, j-1, n, m, idx+1, word);
        bool down = check(board, i+1, j, n, m, idx+1, word);
        bool right = check(board, i, j+1, n, m, idx+1, word);

        board[i][j] = ch;
        
        if(left or right or up or down){
            return true;
        }

        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){                    
                    if(check(board, i, j, n, m, 0, word)){
                        return true;
                    }
                }
            }
        }
        
        return false;        
    }
};