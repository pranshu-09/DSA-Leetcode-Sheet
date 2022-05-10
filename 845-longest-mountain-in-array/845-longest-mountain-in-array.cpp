class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int longest_length = 0;
        
        for(int i=1;i<arr.size()-1;){
            
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
                
                int len = 1;
                int idx = i;
                
                // Left Traversal
                while(idx>0 and arr[idx]>arr[idx-1]){
                    len++;
                    idx--;
                }
                
                // Right Traversal
                idx = i;
                while(idx<arr.size()-1 and arr[idx]>arr[idx+1]){
                    len++;
                    idx++;
                }
                
                longest_length = max(longest_length, len);
                i = idx+1;
            }
            else{
                i++;
            }
        }
        
        return longest_length;
    }
};