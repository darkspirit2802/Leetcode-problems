class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        vector<int> vec(2 * n);

        // duplicate array
        for(int i = 0; i < n; i++) {
            vec[i] = nums[i];
            vec[i + n] = nums[i];
        }

        // copy rotated part back to nums
        for(int i = 0; i < n; i++) {
            nums[i] = vec[n - k + i];
        }
    }
};