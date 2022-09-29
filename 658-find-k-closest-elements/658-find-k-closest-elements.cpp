class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>>temp;
        vector<int>ans;
        
        for(auto elem : arr){
            temp.push_back({abs(x-elem), elem});
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};