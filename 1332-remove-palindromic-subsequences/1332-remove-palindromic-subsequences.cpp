// TC : O(N)
// SC : O(1)
class Solution {
public:
    int removePalindromeSub(string s) {
        
        int a = 0, b = 0;
        
        for(auto x : s){
            if(x == 'a') a++;
            else b++;
        }
        
        if(a==0 or b==0) return 1;
        
        int i=0, j=s.size()-1;
        bool check = true;
        
        while(i<=j){
            if(s[i] != s[j]){
                check = false;
                break;
            }
            
            i++;
            j--;
        }
        
        if(check) return 1;
        
        return 2;
    }
};