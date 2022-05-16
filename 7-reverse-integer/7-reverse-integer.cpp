// TC : O(log(x))
// SC : O(1)

class Solution {
public:
    int reverse(int x) {
        
        int rev = 0;
        
        while(x != 0){
            int a = x%10;
            
            if(rev > (INT_MAX/10) or (rev==INT_MAX/10 and a>7)) return 0;
            if(rev < (INT_MIN/10) or (rev==INT_MIN/10 and a<-8)) return 0;
            
            rev = rev*10 + a;
            x /= 10;
        }
        
        return rev;
    }
};