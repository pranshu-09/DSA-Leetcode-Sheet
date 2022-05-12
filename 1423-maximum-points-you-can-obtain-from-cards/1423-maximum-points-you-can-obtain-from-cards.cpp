// TC : O(K) {if K~N => O(N)}
// SC : O(1)

// sliding window + 2 pointer
/*
Suppose k=3, there can be following ways to pick elements from start and end
      Start    End
        3       0
        1       2
        2       1
        0       3

So, we can make a window of size k from start or end (say start), and find its sum
Then, start subtracting one element from start and add one element from end till we get the maximum points
*/

class Solution {
public:

    int maxScore(vector<int>& nums, int k) {
     
        int n = nums.size();
        
        int start_sum = 0;
        for(int i=0;i<k;i++){
            start_sum += nums[i];
        }
        
        // initialise pointers for start and end
        int i = k-1;    // since subtracting will begin from last term added from start
        int j = n-1;
        
        int ans = start_sum;
        
        while(i>=0){  
            start_sum = start_sum - nums[i] + nums[j];
            ans = max(ans, start_sum);
            
            i--;
            j--;
        }
        
        return ans;
    }
};