// TC : O(NlogN)
// SC : O(1)

class Solution {
public:
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        for(int i=0;i<rocks.size();i++){
            capacity[i] -= rocks[i];
        }
        
        sort(capacity.begin(), capacity.end());
        
        int i=0;
        int ans = 0;
        
        while(i<rocks.size() and additionalRocks>0){
            additionalRocks -= capacity[i];
            
            if(additionalRocks>=0){
                ans++;
            }
            i++;
        }
        
        return ans;
    }
};