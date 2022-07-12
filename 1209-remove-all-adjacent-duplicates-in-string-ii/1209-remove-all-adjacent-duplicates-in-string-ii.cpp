// TC :  O(N)
// SC :  O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++){
            
            if(st.empty() or s[i]!=st.back().first){
                st.push_back({s[i], 1});
            }
            else if(++(st.back().second) == k){
                st.pop_back();
            }
        }
        
        string ans = "";
        
        for(auto x : st){
            while(x.second--){
                ans += x.first;
            }
        }
        
        return ans;
    }
};