class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int i = n - 1;
        long long result = 0;
        while (i >= 0 && k > 0) {
            if (mul <= 0) {
                result += (long long)nums[i];
            } else {
                result += (long long)nums[i] * (long long)mul;
            }
            k--;
            i--;
            mul--;
        }
        return result;
    }
};