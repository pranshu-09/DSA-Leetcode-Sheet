// TC : O(N)
// SC : O(N)
class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        bool all_one = true;
        for(auto x : target){
            if(x != 1){
                all_one = false;
                break;
            }
        }
        
        if(all_one) return true;
        
        long long int sum = 0;
        
        priority_queue<int>pq;
        for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum += target[i];
        }
        
        while(sum>1 and pq.top()>(sum/2)){
            
            int val = pq.top();
            pq.pop();
            
            sum -= val;
            
            if(sum <= 1){
                return sum;
            }
            
            pq.push(val%sum);
            sum += (val%sum);
        }
        
        return sum == target.size();
    }
};