// TC : O(N)
// SC : O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int goal = n-1;
        
        // we want to reach the last index of the array, so what if we start checking from the right of the array.
        // We can maintain a goal index and check if we add nums[i] to i, can we reach the goal index.
        // If we can reach it, then update goal with current index because we know for sure that from current index, it can definitely reach the end of the array;
        
        for(int i=n-1;i>=0;i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        
        // if in the end, goal value comes to 0, it means the we can reach the end of array with jumps
        // if goal != 0, then there must be a position where no further movement can be made
        return goal == 0;
    }
};