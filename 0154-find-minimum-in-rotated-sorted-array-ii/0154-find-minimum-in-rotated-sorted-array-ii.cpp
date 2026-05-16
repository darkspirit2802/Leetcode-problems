class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];

        int l = 0;
        int r = n-1;

        while(l<n && nums[l] == last){
            l++;
        }

        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return nums[r];
        
    }
};