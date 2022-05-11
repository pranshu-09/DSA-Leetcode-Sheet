// TC : O(N)
// SC : O(1)

/*
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        nums.push_back(0);
        
        for(int i=0;i<nums.size();i++){
            
            int x = nums[i];
            
            if(x != nums[x]){
                swap(nums[i], nums[x]);
                
                while(nums[i] != nums[nums[i]]){
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(i != nums[i]){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(nums[abs(val)-1] < 0){
                ans.push_back(abs(val));
            }
            else{
                nums[abs(val)-1] = -nums[abs(val)-1];
            }
        }
        
        return ans;
    }
};
