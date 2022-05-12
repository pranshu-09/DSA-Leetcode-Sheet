// TC : O(NxM)
// SC : O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int sr=0, sc=0;
        int er=matrix.size()-1, ec=matrix[0].size()-1;
        
        vector<int>ans;
        
        while(sr<=er and sc<=ec){
            // left to right
            for(int i=sc;i<=ec;i++){
                ans.push_back(matrix[sr][i]);
            }
            sr++;

            // top to bottom
            for(int i=sr;i<=er;i++){
                ans.push_back(matrix[i][ec]);
            }
            ec--;

            // right to left
            // in horizontal matrix of size like (3x4), terms may repeat since by the first loop, sr has become greater than er but it is still in the loop.
            // so, it has to be handled by adding an if condition
            if(sr<=er){
                for(int i=ec;i>=sc;i--){
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }

            // bottom to top
            // in vertical matrix of size like (3x1), terms may repeat since by the first loop, ec has become less than sc but it is still in the loop.
            // so, it has to be handled by adding an if condition
            if(sc<=ec){
                for(int i=er;i>=sr;i--){
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
    
        return ans;
    }
    
};