// TC : O(N)
// SC : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        nums.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            while(nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }            
        }
        
        for(int i=0;i<nums.size();i++){
            if(i != nums[i]){
                return i;
            }
        }
        
        return 0;
    }
};

// TC : O(N)
// SC : O(1)
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int xorr = 0;
        
        for(int i=0;i<=n;i++){
            xorr ^= i;
        }
        
        for(int i=0;i<n;i++){
            xorr ^= nums[i];
        }
        
        return xorr;
    }
};
*/