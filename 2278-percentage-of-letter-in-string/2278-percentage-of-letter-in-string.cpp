// TC : O(N)
// SC : O(1)

class Solution {
public:
    int percentageLetter(string s, char letter) {
        
        int cnt = 0;
        for(auto x : s){
            if(x == letter){
                cnt++;
            }
        }
        
        if(cnt == 0) return 0;
        
        double per = (cnt*100)/(s.size()*1.0);
        
        return floor(per);
    }
};