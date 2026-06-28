class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        arr[0] = 1;
        int maxEl = arr[0];

        for(int i = 1;i<n;i++){
            int diff = abs(arr[i]-arr[i-1]);
            if(diff > 1){
                arr[i] = arr[i-1] + 1;
            }
            maxEl = max(maxEl,arr[i]);
        }
        return maxEl;
        
    }
};