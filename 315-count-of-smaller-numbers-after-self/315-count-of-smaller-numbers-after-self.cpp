class Solution {
public:
    
    void merge_count(vector<int>& indices, int first, int last, vector<int>& results, vector<int>& nums) {
        
        int count = last - first;
        
        if (count>1) {
            
            int step = count / 2;
            int mid = first + step;
            
            merge_count(indices, first, mid, results, nums);
            merge_count(indices, mid, last, results, nums);
            
            vector<int> tmp;
            tmp.reserve(count);
            
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            
            while ((idx1 < mid) or (idx2 < last)) {
                
                if ((idx2 == last) or ((idx1 < mid) and (nums[indices[idx1]] <= nums[indices[idx2]]))) {
					tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } 
                else {
					tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        
        for(int i=0;i<n;i++){
            indices[i] = i;
        }
        
        merge_count(indices, 0, n, results, nums);
        
        return results; 
    }
};