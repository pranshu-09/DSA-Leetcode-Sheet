// TC : O(N)
// SC : O(numRows)
class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        
        string temp[numRows];
        
        int row = 0;
        int step = 1;
        
        for(int i=0;i<s.size();i++){
            
            temp[row] += s[i];
            
            if(row == 0) step = 1;
            else if(row == numRows-1) step = -1;
            
            row += step;
        }
        
        string ans = "";
        
        for(auto x : temp){
            ans += x;
        }
        
        return ans;           
    }
};