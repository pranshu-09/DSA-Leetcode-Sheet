// TC : O(N)
// SC : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int i=0, j=n-1;
        
        int water = 0;
        
        // our task is to find max capacity
        // capacity can be determined by: width x height
        //                                (j-i) x min(height[i], height[j])
        // start from i=0 and j=n-1
        // capacity depends upon min(height[i], height[j]) and width of j-i. So, to check for other vessels, we will inc i or dec j.
        // if the width will be decreased, the height has to be increased. For increasing height, min of height[i] and height[j] has to be increased.
        // so, update the min of the two.
        // Note: if height[i]==height[j], then it does not matter whether you perform i++ or j--
        // because if h[i] == h[j], neither (i+1, j) or (i, j-1) can be potential solutions because the area obtained is necessarily smaller than (i, j).
        
        while(i<j){
            
            int cur = (j-i)*(min(height[i], height[j]));
            water = max(water, cur);
            
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }            
        }
        
        return water;        
    }
};