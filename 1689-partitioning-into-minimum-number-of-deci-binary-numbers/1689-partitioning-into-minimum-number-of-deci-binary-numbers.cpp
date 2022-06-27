class Solution {
public:
    int minPartitions(string n) {
        
        int min_need = 0;
        
        for(int i=0;i<n.size();i++){
            
            if(n[i]-'0' == 9){
                return 9;
            }
            
            min_need = max(min_need, n[i]-'0');
        }
        
        return min_need;
    }
};