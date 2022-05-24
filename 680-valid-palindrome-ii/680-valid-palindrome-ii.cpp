// TC : O(N)
// SC : O(1)

class Solution {
public:
    
    bool check_pal(string s, int i, int j){
        
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    bool validPalindrome(string str) {
        
        int s=0;
        int e=str.size()-1;
        
        while(s<e){
            
            if(str[s]==str[e]){
                s++;
                e--;
            }
            else{
                return check_pal(str, s+1, e) or check_pal(str, s, e-1);
            }
        }
        
        return true;
    }
};