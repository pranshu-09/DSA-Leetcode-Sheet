class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        
        int num = x;
        long num2 = 0;
        
        while(num != 0){
            num2 = num2*10 + (num%10);
            num /= 10;
        }
        
        return num2 == x;
    }
};