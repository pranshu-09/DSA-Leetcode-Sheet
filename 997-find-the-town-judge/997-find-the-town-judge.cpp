// TC : O(N)
// SC : O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        map<int, list<int>>m;
        
        int count[1001] = {0};
        
        for(int i=0;i<trust.size();i++){
            m[trust[i][0]].push_back(trust[i][1]);
            count[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(m[i].size()==0 and count[i]==n-1){
                return i;
            }
        }
        
        return -1;
    }
};