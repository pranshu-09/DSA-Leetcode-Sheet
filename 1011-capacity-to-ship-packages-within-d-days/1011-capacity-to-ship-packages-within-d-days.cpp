// TC : O(NlogN)
// SC : O(1)

class Solution {
public:
    
    bool is_valid(vector<int>& weights, int days, int wt){
        
        int d = 0;
        int n = weights.size();
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += weights[i];
            
            if(sum > wt){
                sum = weights[i];
                d++;
                
                if(d >= days){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int minw = 0, maxw = 0;
        for(auto x : weights){
            minw = max(minw, x);
            maxw += x;
        }
        
        int ans = 0;
        
        while(minw <= maxw){
            
            int mid = minw + (maxw - minw)/2;
            
            if(is_valid(weights, days, mid)){
                ans = mid;
                maxw = mid - 1;
            }
            else{
                minw = mid + 1;
            }
        }
        
        return ans;
    }
};