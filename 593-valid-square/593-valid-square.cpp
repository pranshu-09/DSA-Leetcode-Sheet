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
        
        // rbegin returns the last element of the map
        if(dis.begin()->first==0 or dis.rbegin()->first==0) return false;
        
        return dis.begin()->second==4 and dis.rbegin()->second==2;
    }
};