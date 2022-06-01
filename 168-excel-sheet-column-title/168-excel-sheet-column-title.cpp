// TC : o(log26(columnNumber))
// SC : o(1)

class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        
        while(columnNumber != 0){
            
            columnNumber -= 1;
            
            int rem = columnNumber%26;
            char ch = rem + 'A';
            ans = ch + ans;
        
            columnNumber /= 26;
        }
        
        return ans;
    }
};