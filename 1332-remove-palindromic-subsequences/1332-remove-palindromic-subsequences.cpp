// TC : O(N)
// SC : O(1)
class Solution {
public:
    int removePalindromeSub(string s) {
                
        int i=0, j=s.size()-1;
        bool check = true;
        
        while(i<j){
            if(s[i] != s[j]){
                return 2;
            }
            
            i++;
            j--;
        }
        
        return 1;
    }
};