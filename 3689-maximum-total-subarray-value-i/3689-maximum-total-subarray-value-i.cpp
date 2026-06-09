class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       
        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,(long long)nums[i]);
            mini = min(mini,(long long)nums[i]);
        }
        long long diff = maxi - mini;
        long long ans = diff * k;

        return ans;
    }
};