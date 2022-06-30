// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // 0 0 1 6 8
        // i       j
        
        // i should be equal to j
        // add something (x) in 0 and subtract something (y) from 8 to make them equal
        // 0+x = 8-y => x+y = 8-0 => add 8 in the ans => do i++, j--
        
        int i=0, j=n-1;
        int ans = 0;
        
        while(i < j){
            ans += (nums[j]-nums[i]);
            i++;
            j--;
        }
        
        return ans;
    }
};


/*
// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int median = (n&1) ? nums[n/2] : (nums[n/2] + nums[n/2 - 1])/2;
        
        int ans = 0;
        for(auto x : nums){
            ans += (abs(median-x));
        }
        
        return ans;
    }
};
*/