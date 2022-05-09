// bool cmp(vector<int>a, vector<int>b){
//     if(a[1] == b[1]){
//         return a[0] < b[0];
//     }
//     else{
//         return a[1] < b[1];
//     }
// }

class Solution {
    
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        
        sort(intervals.begin(), intervals.end());
        
        ans.push_back(intervals[0]);
        
        int prev_end = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= prev_end){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
            prev_end = ans.back()[1];
        }
        
        return ans;
    }
};