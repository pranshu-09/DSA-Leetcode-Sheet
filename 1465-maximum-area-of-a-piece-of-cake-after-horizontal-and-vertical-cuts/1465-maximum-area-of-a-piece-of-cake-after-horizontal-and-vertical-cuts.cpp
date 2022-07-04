// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        // Horizontal Cuts
        horizontalCuts.push_back(h);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        int max_h = horizontalCuts[0] - 0;
        
        for(int i=1; i<horizontalCuts.size(); i++){
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        // Vertical Cuts
        verticalCuts.push_back(w);
        
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_v = verticalCuts[0] - 0;
        
        for(int i=1; i<verticalCuts.size(); i++){
            max_v = max(max_v, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return (1LL*max_h*max_v) % 1000000007;
    }
};