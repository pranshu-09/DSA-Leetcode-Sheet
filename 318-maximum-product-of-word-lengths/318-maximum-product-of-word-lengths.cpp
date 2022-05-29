// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        vector<int>binary(n);
        
        // Form binary representation of each word
        for(int i=0;i<words.size();i++){
            for(auto x : words[i]){
                binary[i] = binary[i]|(1<<(x-'a'));
            }
        }
        
        int max_prod = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((binary[i] & binary[j])==0){
                    int prod = (words[i].size()*words[j].size());
                    max_prod = max(max_prod, prod);
                }
            }
        }
        
        return max_prod;
    }
};