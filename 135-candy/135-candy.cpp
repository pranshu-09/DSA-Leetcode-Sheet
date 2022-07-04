class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        int ans=n;
        int i=1;
        
        while(i<n){
            
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //Increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                ans += peak;
                i++;
                
                if(i == n) 
                    return ans;
            }
            
            //Decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                ans += valley;
                i++;
            }
            
            ans -= min(peak, valley); //Keep only the higher peak
        }
        
        return ans;
    }
};