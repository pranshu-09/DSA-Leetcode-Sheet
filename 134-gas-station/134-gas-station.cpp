// TC : O(N)
// SC : O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gs = 0;
        for(auto x : gas) gs += x;
        
        int cs = 0;
        for(auto x : cost) cs += x;
        
        if(cs > gs){
            return -1;
        }
        
        int cur = 0;
        int start = 0;
        
        for(int i=0;i<gas.size();i++){
            cur += (gas[i] - cost[i]);
            
            if(cur < 0){
                cur = 0;
                start = i+1;
            }
        }
        
        return start;
    }
};