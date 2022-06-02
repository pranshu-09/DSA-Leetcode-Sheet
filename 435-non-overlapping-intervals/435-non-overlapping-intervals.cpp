// TC : O(NlogN)
// SC : O(1)

bool cmp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int ans = 0;
        
        int prev_int = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < prev_int){
                ans++;
            }
            else{
                prev_int = intervals[i][1];
            }
        }
        
        return ans;
    }
};