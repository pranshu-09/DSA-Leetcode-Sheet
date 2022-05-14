class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        int cnt = 0;
        
        string no = to_string(num);
        
        for(int i=0;i<=no.size()-k;i++){
            
            string s = no.substr(i, k);
            int val = stoi(s);
            
            if(val!=0 and num%val==0){
                cnt++;           
            }
        }
        
        return cnt;
    }
};