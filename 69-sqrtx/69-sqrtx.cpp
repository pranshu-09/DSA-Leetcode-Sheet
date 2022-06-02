// TC : O(logN)
// SC : O(1)
class Solution {
public:
    int mySqrt(int x) {
        
        int s = 0, e = x;
        
        while(s <= e){
            
            long long mid = s + (e-s)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return s-1;
    }
};