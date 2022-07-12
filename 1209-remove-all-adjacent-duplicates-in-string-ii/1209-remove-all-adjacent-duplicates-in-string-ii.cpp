// TC :  O(N)
// SC :  O(N)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++){
            
            if(st.empty() or s[i]!=st.top().first){
                st.push({s[i], 1});
            }
            else if(s[i] == st.top().first){
                st.push({s[i], st.top().second + 1});
            }
            
            if(st.top().second == k){
                int t = k;
                while(t--){
                   st.pop(); 
                }
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};