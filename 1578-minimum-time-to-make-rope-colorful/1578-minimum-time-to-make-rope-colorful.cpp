// TC : O(N)
// SC : O(N)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();
        
        if(n==1) return 0;
        
        int ans = 0;
        
        for(int i=1;i<n;){
            
            if(colors[i] == colors[i-1]){
                
                int max_need = neededTime[i-1];
                int sum = neededTime[i-1];      
                int data = colors[i-1];
                
                while(i<n and colors[i]==data){
                    max_need = max(max_need, neededTime[i]);
                    sum += neededTime[i];
                    i++;
                }
                
                ans += (sum - max_need);
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};