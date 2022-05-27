// TC : O(NxM)
// SC : O(M)

class Solution {
public:
    
    int n, m;
    
    int find_max(vector<int>&hist){
        
        stack<int>s;
        int area=0, max_area=0;
        int i;
        
        for(i=0;i<m;){
            if(s.empty() or hist[i]>=hist[s.top()]){
                s.push(i);
                i++;
            }
            else{            
                int k = s.top();
                s.pop();
                
                if(s.empty()){
                    area = hist[k]*(i);
                }
                else{
                    area = hist[k]*(i-s.top()-1);
                }
    
                max_area = max(max_area, area);
            }
        }
        
        while(!s.empty()){
            
            int k = s.top();
            s.pop();

            if(s.empty()){
                area = hist[k]*(i);
            }
            else{
                area = hist[k]*(i-s.top()-1);
            }

            max_area = max(max_area, area);
        }
        
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        n = matrix.size();
        m = matrix[0].size();
        
        // find max rectangle in histogram logic
        // For each row, calculate the size of each histogram, i.e. length of 1's from (0, j) to (i, j)
        vector<int>hist(m);
        
        for(int i=0;i<m;i++){
            hist[i] = matrix[0][i]-'0';
        }
        
        int area = 0, max_area = 0;
        
        for(int i=0;i<n;i++){
            
            // update hist array with current lengths (including current row)
            if(i!=0){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]=='0'){
                        hist[j] = 0;
                    }
                    else{
                        hist[j] += 1;
                    }
                }
            }
            
            area = find_max(hist);
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};