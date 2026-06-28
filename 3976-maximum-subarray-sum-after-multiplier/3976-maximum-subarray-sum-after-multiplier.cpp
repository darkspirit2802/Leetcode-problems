class Solution {
public:
    long long solve(vector<int>& nums, int k, bool multiply) {

        auto convert = [&](int x) -> long long {
            if (multiply)
                return 1LL * x * k;

            if (x >= 0)
                return x / k;

            return (long long)ceil((double)x / k);
        };

        const long long NEG = -4e18;

        long long dp0 = NEG;
        long long dp1 = NEG;
        long long dp2 = NEG;

        long long ans = NEG;

        for (int x : nums) {

            long long y = convert(x);

            long long ndp0 = max(dp0 + x, 1LL * x);

            long long ndp1 = max({
                y,
                dp0 + y,
                dp1 + y
            });

            long long ndp2 = max(
                dp1 + x,
                dp2 + x
            );

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;

            ans = max({ans, dp0, dp1, dp2});
        }

        return ans;
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(
            solve(nums, k, true),
            solve(nums, k, false)
        );
    }
};