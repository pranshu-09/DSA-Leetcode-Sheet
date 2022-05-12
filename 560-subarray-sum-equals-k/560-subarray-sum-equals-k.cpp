// TC : O(N)
// SC : O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int cur_sum = 0;        // to store current sum
        int n = nums.size();
        int count = 0;
        
        // to store frequency of current sum available
        unordered_map<int, int>freq;
        
        // when the element of nums itself is equal to k
        freq[0] = 1;
        
        // find the frequency of sum such that cur_sum - k = this sum. Hence, we can find subarrays with k as the sum.
        for(int i=0;i<n;i++){
            
            cur_sum += nums[i];
            
            if(freq.find(cur_sum - k) != freq.end()){
                count += freq[cur_sum - k];
            }
            
            // add current sum frequency which will be used later
            freq[cur_sum]++;
        }
        
        return count;
    }
};


// TC : O(N^2)
// SC : O(N)

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        
        int prefix[n];
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum;
                if(i==0){
                    sum = prefix[j];
                }
                else{
                    sum = prefix[j] - prefix[i-1];
                }
                if(sum == k){
                    count++;
                }
            }
        }
        
        return count;
    }
};
*/