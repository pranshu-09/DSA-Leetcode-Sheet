class Solution {
public:
    
    void reverse_letters(string&s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        
        int n = s.size();
        int i = 0, j=0;
        
        while(j<n){
            
            if(s[j] != ' '){
                j++;
            }
            else{
                reverse_letters(s, i, j-1);
                i = j+1;
                j++;
            }
        }
        
        reverse_letters(s, i, j-1);
        
        return s;
    }
};