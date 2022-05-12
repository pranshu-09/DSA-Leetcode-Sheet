// TC : O(Nlog(N))
// SC : O(1)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i=0, j=1;
        
        int count = 0;
        
        while(j<n){
            
            if(i==j or nums[j]-nums[i]<k){
                j++;
            }
            else{
                if(nums[j]-nums[i] == k){
                    
                    count++;
                    int val = nums[j];
                    
                    while(j<n and nums[j]==val){
                        j++;
                    }
                    
                    if(j == n){
                        return count;
                    }
                }
                
                int val = nums[i];
                while(i<j and nums[i]==val){
                    i++;
                }
            } 
        }
        
        return count;
    }
};

// TC : O(N)
// SC : O(N)

/*
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int>m;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        if(k==0){
            for(auto x : m){
                if(x.second >= 2){
                    count++;
                }
            }
            return count;
        }
        
        for(auto x : m){
            if(m.find(x.first-k) != m.end()){
                count++;
            }
        }
        
        return count;
    }
};
*/