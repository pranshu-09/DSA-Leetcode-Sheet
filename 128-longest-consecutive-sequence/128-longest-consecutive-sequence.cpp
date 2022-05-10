// TC : O(N)
// SC : O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0){
            return 0;
        }
        
        // Approach: Find the head of each sequence.
        //           It can be found as make a set and insert all elements in it. If (current element-1) is present in set, it means it is not head.
        //           If it is not present, then it is head, then traverse till (cur elem + 1) is present in the set and increment count and find max sequeunce length.
        
        int long_seq = 0;
        
        unordered_set<int>s(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            
            int cur = nums[i];
            
            if(s.find(cur-1) == s.end()){
                
                // traverse till cur+1 present in set
                int seq = 1;
                while(s.find(cur+1) != s.end()){
                    cur++;
                    seq++;
                }
                
                long_seq = max(long_seq, seq);
            }
        }
        
        return long_seq;
    }
};