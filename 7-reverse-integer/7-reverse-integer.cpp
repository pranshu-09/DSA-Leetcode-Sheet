class Solution {
public:
    int reverse(int x) {
        
        long long int y = x;
        long long int rev = 0;
        
        bool neg = false;
        if(y<0){
            neg = true;
            y = abs(y);
        }
        
        while(y!=0){
            int a = y%10;
            rev = rev*10 + a;
            y = y/10;
        }
        
        if(neg) rev = -rev;
        
        if(rev<INT_MIN or rev>INT_MAX)
            return 0;
        
        return rev;
    }
};