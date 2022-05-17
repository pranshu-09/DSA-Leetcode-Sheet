// TC : O(N)
// SC : O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.size();
        int m = b.size();
        
        if(n>m){
            return addBinary(b, a);
        }
        
        while(n<m){
            a = '0' + a;
            n++;
        }
        
        // ans will be stored in string 'a'  
        int carry = 0;
        for(int i=n-1;i>=0;i--){
            int x = a[i]-'0';
            int y = b[i]-'0';
            int sum = x+y+carry;
            
            a[i] = (sum%2) + '0';
            carry = sum/2;
        }
        
        if(carry){
            a = '1' + a;
        }
        
        return a;
    }
};