// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        
        // similar approach as House Robber Problem
        
        sort(nums.begin(), nums.end());
        
        int i=0, n = nums.size();
        int a=0, b=0;
        
        // consider all same elements as 1. They will give points = nums[i]*freq
        
        // when nums have all same elements
        int data = nums[0];
        int freq = 0;
        
        while(i<n and data==nums[i]){
            i++;
            freq++;
        }
        a = data*freq;
        
        if(i==n) return a;
        
        
        // when nums have all 2 unqiue elements
        data = nums[i];
        freq = 0;
        while(i<n and data==nums[i]){
            i++;
            freq++;
        }
        if(data - nums[0]==1){
            b = max(a, data*freq);
        }
        else{
            b = a + data*freq;
        }
        
        if(i==n) return b;
        
        int prev = data;
        
        while(i < n){
            
            data = nums[i];
            freq = 0;
            int c;
            
            while(i < n and data==nums[i]){
                i++;
                freq++;
            }
            
            if(data - prev == 1){
                c = max(a + data*freq, b);
            }
            else{
                c = b + data*freq;
            }
            
            a = b;
            b = c;
            
            prev = data;
        }
        
        return b;
    }
};

// Recursion
/*
class Solution {
public:
    
    int max_points(vector<int>& nums, int i, unordered_map<int, int>m){
        
        if(i==nums.size()){
            return 0;
        }
        
        if(m[nums[i]]==0){
            return max_points(nums, i+1, m);
        }
        
        int t1 = m[nums[i]-1];
        m[nums[i]-1] = 0;
        
        int t2 = m[nums[i]+1];
        m[nums[i]+1] = 0;
        
        int inc = max_points(nums, i+1, m) + nums[i];
        
        m[nums[i]-1] = t1;
        m[nums[i]+1] = t2;
        
        int exc = max_points(nums, i+1, m);
        
        return max(inc, exc);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int,int>m;
        
        for(auto x : nums){
            m[x]++;
        }
        
        return max_points(nums, 0, m);
    }
};
*/