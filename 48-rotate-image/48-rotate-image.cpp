// TC : O(NxM)
// SC : O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // swap elements about left diagonal => [i][j] <=> [j][i]
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse individual rows of the matrix
        for(int row=0;row<n;row++){
            int i=0, j=m-1;
            while(i<j){
                swap(matrix[row][i], matrix[row][j]);
                i++;
                j--;
            }
        }
    }
};