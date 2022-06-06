class Solution {
public:
    
    string decode(string&s, int&i){
        
        string ans = "";
        int num = 0;
        
        while(i < s.size()){
            
            if(s[i]>='a' and s[i]<='z'){
                ans += s[i];
                i++;
            }
            else if(s[i]>='0' and s[i]<='9'){
                num = num*10 + (s[i]-'0');
                i++;
            }
            else if(s[i] == '['){
                i++;
                string rest = decode(s, i);

                while(num--){
                    ans += rest;
                }
                num = 0;
            }
            else{
                i++;
                break;
            }
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};