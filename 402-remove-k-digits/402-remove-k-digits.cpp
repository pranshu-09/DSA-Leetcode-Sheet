// TC : O(N)
// SC : O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>s;
        s.push(num[0]);
        
        for(int i=1;i<num.size();i++){
            if(s.top() <= num[i]){
                s.push(num[i]);
            }
            else{
                while(!s.empty() and s.top() > num[i] and k!=0){
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        int i = 0;
        for(i;i<ans.size();i++){
            if(ans[i]!='0') break;
        }
        
        ans = ans.substr(i);
        
        while(k!=0 and ans.size()){
            ans.pop_back();
            k--;
        }
        
        if(ans.size()==0) return "0";
        
        return ans;        
    }
};