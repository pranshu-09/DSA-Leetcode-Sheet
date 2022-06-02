// TC : O(logN)
// SC : O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
     
        int s = 1, e=arr.size()-1;
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1] and arr[mid]<arr[mid+1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            
        }
        
        return -1;
    }
};