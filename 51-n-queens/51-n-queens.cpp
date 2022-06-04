class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool can_place(vector<string>&board, int row, int col, int n){
        
        // cur row
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q') return false;
        }
        
        // cur col
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        
        // left diagonal
        int i=row-1, j=col-1;
        while(i>=0 and j>=0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
        // right diagonal
        i=row-1, j=col+1;
        while(i>=0 and j<n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        
        return true;
    }
    
    bool find_pos(vector<string>&board, int row, int n){
        
        if(row == n){
            ans.push_back(board);
            return false;
        }
        
        for(int col=0;col<n;col++){
            if(can_place(board, row, col, n)){
                
                board[row][col] = 'Q';
                bool res_board = find_pos(board, row+1, n);
                
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string>board(n);
        for(int k=0;k<n;k++){
            string s = "";
            for(int i=0;i<n;i++) s += '.';
            board[k] = s;
        }
        
        find_pos(board, 0, n);
        
        return ans;
    }
};