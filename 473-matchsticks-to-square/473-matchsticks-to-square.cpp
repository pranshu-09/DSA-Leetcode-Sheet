class Solution {
public:
    
    bool check_pos(vector<int>& m, int idx, int sides[4], int target){
        
        if(idx == m.size()){
            
            if(sides[0]==target and sides[1]==target and sides[2]==target and sides[3]==target){
                return true;
            }
            
            return false;
        }
        
        for(int sd=0;sd<4;sd++){
            
            if(sides[sd]+m[idx] > target){
                continue;
            }
            
            int j = sd;
            
            while(--j >= 0){
                if(sides[sd] == sides[j]){
                    break;
                }
            }
            
            if (j != -1){ 
                continue;
            }
            
            sides[sd] += m[idx];
            
            if(check_pos(m, idx+1, sides, target)){
                return true;
            }
            
            sides[sd] -= m[idx];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        if(matchsticks.size()<4){
            return false;
        }
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        int sum = 0;
        for(auto x : matchsticks){
            sum += x;
        }
        
        if(sum%4 != 0){
            return false;
        }
        
        int sides[4] = {0};
        
        return check_pos(matchsticks, 0, sides, sum/4);        
    }
};