// TC : O(N)
// SC : O(N)

class Solution {
public:
    int calculate(string s) {
        
        if(s.size()==0) return 0;
        
        int n = s.size();
        
        stack<int>st;
        int cur = 0;
        char oper = '+';
        
        for(int i=0;i<n;i++){
            
            if(s[i]>='0' and s[i]<='9'){
                cur = cur*10 + (s[i]-'0');
            }
            
            if(!(s[i]>='0' and s[i]<='9') and (s[i]!=' ') or i==n-1){
                
                if(oper=='+'){
                    st.push(cur);
                }
                else if(oper=='-'){
                    st.push(-cur);
                }
                else if(oper=='*'){
                    int top = st.top();
                    st.pop();
                    st.push(top*cur);
                }
                else if(oper=='/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/cur);
                }
                
                oper = s[i];
                cur = 0;
            }
        }
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};
