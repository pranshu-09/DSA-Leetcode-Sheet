class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        
        // k => carpet length
        sort(tiles.begin(), tiles.end());
        
        int n = tiles.size();
        
        vector<int>start;
        for(auto x : tiles){
            start.push_back(x[0]);
        }
        
        vector<int>sum(n, 0);
        sum[0] = tiles[0][1] - tiles[0][0] + 1;
        
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1] + (tiles[i][1] - tiles[i][0] + 1);
        }
        
        int max_tiles = 0;
        
        for(int i=0;i<n;i++){
            
            if((tiles[i][1] - tiles[i][0] + 1) >= k){
                return k;
            }
            
            // find index of the tile interval if it will be partially covered with the carpet
            int idx = upper_bound(start.begin(), start.end(), start[i] + k - 1) - start.begin()-1;
            
            int rest_len = 0;
            
            if(tiles[i][0] + k - 1 < tiles[idx][1]){
                rest_len = tiles[idx][1] - (tiles[i][0] + k - 1);
            }
                
            int t = 0;
            
            if(i!=0) 
                t = sum[i-1];
        
            int len_covered = sum[idx] - t - rest_len;     
            max_tiles = max(max_tiles, len_covered);
        }
        
        return max_tiles;
    }
};