// TC : O(logN)
// SC : O(1)

class Solution {
public:
    int numberOfSteps(int num) {
        
        int ans = 0;
        
        while(num!=0){
            
            if(num==1){
                ans++;
                break;
            }
            
            if(num&1){
                ans += 2;
            }
            else{
                ans += 1;
            }
            num = num>>1;
        }
        
        return ans;
    }
};