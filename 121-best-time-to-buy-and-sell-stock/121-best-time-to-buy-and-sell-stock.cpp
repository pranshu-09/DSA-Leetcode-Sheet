// TC = O(N)
// SC = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = INT_MAX;    // min so far
        int prof = 0;
        
        for(int i=0;i<prices.size();i++){
            buy = min(buy, prices[i]);
            
            int sell = prices[i] - buy;
            
            prof = max(prof, sell);
        }
        
        return prof;
    }
};