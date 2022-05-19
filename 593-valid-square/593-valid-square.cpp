// TC : O(1)
// SC : O(1)

class Solution {
public:
    
    int find_len(vector<int>&p1, vector<int>&p2){
        return ((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int>dis;
        dis[find_len(p1, p2)]++;
        dis[find_len(p1, p3)]++;
        dis[find_len(p1, p4)]++;
        dis[find_len(p2, p3)]++;
        dis[find_len(p2, p4)]++;
        dis[find_len(p3, p4)]++;
        
        // four sides of square should be equal and 2 diagonals should be equal. Hence, the distance map should contain only 2 elements and distance should not be 0
        if(dis.size()!=2){
            return false;
        }
        
        int d1, cnt1;
        int d2, cnt2;
        
        int p = -1;
        
        for(auto x : dis){
            if(p == -1){
                d1 = x.first;
                cnt1 = x.second;
                p = 1;
            }
            else{
                d2 = x.first;
                cnt2 = x.second;
            }
        }
        
        if(d1==0 or d2==0) return false;
        
        return cnt1==4 and cnt2==2;
    }
};