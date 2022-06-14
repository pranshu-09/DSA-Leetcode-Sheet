class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN and divisor==-1){
            return INT_MAX;
        }
        
        long long dvd = labs(dividend);
        long long dvr = labs(divisor);
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        long long ans = 0;
        
        while(dvr <= dvd){
            
            long long temp = dvr;
            long long m = 1;
            
            while(temp<<1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            
            dvd -= temp;
            ans += m;
        }
        
        return sign * ans;    
    }
};