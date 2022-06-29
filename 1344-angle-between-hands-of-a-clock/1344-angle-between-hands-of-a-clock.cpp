// TC : O(1)
// SC : O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double hour_deg = (hour/12.0)*(360.0);
        hour_deg += ((minutes/60.0)*30.0);
        
        double min_deg = (minutes/60.0)*(360.0);
        
        double ans = min_deg - hour_deg;
        
        if(ans < 0.0){
            ans += 360.0;
        }
        
        return min(ans, 360.0-ans);
    }
};