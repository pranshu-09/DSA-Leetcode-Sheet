// TC : O(N)
// SC : O(N)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int>pq;      // to store the maximum no of bricks used at an 'i'
        int bricks_used = 0;
        
        int i;
        
        for(i=0;i<n-1;i++){
            
            if(heights[i] >= heights[i+1]){
                continue;
            }
            
            int dif = heights[i+1] - heights[i];
            
            if(dif + bricks_used <= bricks){
                bricks_used += dif;
                pq.push(dif);
            }
            else if(ladders > 0){
                
                // get the value where maximum bricks were used in the past
                if(!pq.empty() and pq.top() > dif){
                    int max_so_far = pq.top();
                    pq.pop();
                    
                    bricks_used = bricks_used - max_so_far + dif;
                    pq.push(dif);
                }
                
                ladders--;                
            }
            else{
                break;
            }
        }
        
        return i;
    }
};