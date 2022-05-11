// TC : O(N)
// SC : O(N)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        unordered_map<int, int>m;
        
        for(int i=0;i<n;i++){
            time[i] = time[i]%60;
        }
        
        int pairs = 0;
        
        for(int i=0;i<n;i++){
            if(time[i] == 0 and m.find(0)!=m.end()){
                pairs += m[0];
            }
            else if(time[i]!=0 and m.find(60-time[i])!=m.end()){
                pairs += m[60-time[i]];
            }
            m[time[i]]++;
        }
        
        return pairs;
    }
};