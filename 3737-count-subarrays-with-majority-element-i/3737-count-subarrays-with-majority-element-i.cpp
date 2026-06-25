class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // int total_count = 0;
        // for(int i =0;i<n;i++){
        //     if(nums[i]==target){
        //         total_count++;
        //     }
        // }
        int total_sub = 0;
       for(int i = 0;i<n;i++){
        int target_count = 0;
        for(int j  = i;j<n;j++){
            if(nums[j]==target){
                target_count++;
            }
            if(target_count > (j-i+1)/2){
                total_sub++;
            }
        }
       }
        return total_sub;
    }
};