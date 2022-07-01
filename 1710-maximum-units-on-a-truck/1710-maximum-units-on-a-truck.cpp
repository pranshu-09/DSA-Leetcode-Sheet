// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int cur = 0;
        int i = 0;
        int load = 0;
        
        while(cur < truckSize and i<boxTypes.size()){
            
            if(cur+boxTypes[i][0] <= truckSize){
                cur += boxTypes[i][0];
                load += (boxTypes[i][0] * boxTypes[i][1]);
            }
            else{
                int can_take = truckSize - cur;
                load += (can_take * boxTypes[i][1]);
                cur += can_take;
            }
            i++;
        }
        
        return load;
    }
};