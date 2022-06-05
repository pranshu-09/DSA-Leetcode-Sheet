class Solution {
public:
    
    bitset<9> col, d1, d2;
    int ans;
    
    void solve(int r, int n){
        
        if(r == n){
            ans++;
            return;
        }
        
        for(int c=0;c<n;c++){
            if(!col[c] and !d1[(r-c)+n-1] and !d2[r+c]){
                
                col[c] = 1;
                d1[r-c+n-1] = 1;
                d2[r+c] = 1;
                
                solve(r+1, n);
                
                col[c] = 0;
                d1[r-c+n-1] = 0;
                d2[r+c] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        
        ans = 0;
        
        solve(0, n);
        
        return ans;        
    }
};