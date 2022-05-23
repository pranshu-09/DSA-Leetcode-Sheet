// TC : O(N)
// SC : O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>s;
        int area = 0;
        int max_area = 0;
        
        int i;
        
        for(i=0;i<heights.size();){
            
            if(s.empty() or heights[i]>=heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int idx = s.top();
                s.pop();
                
                if(s.empty()){
                    area = heights[idx]*(i);
                }
                else{
                    area = heights[idx]*(i-s.top()-1);
                }
                
                max_area = max(max_area, area);
            }
        }
        
        while(!s.empty()){
            int idx = s.top();
            s.pop();

            if(s.empty()){
                area = heights[idx]*(i);
            }
            else{
                area = heights[idx]*(i-s.top()-1);
            }

            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};