// TC : O(m+n)
// SC : O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;        // pointer for nums1
        int j = n-1;        // pointer for nums2
        int k = m+n-1;      // pointer for merged array
        
        while(i>=0 and j>=0){
            if(nums1[i] > nums2[j]){            // SUnce we are adding from the back, so greater element will be at the end
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        
        // Insert left elements of nums2 into nums1
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};