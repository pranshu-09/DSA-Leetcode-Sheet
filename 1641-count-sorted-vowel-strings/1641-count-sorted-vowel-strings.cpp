class Solution {
public:
    
    vector<char>vow{'a','e','i','o','u'};
    
    int count_vowel(int n, char ch){
        
        if(n==0){
            return 1;
        }
        
        int ans = 0;
        
        for(int i=0;i<5;i++){
            if(ch <= vow[i]){
                ans += count_vowel(n-1, vow[i]);
            }
        }
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        return count_vowel(n,'a');
    }
};