class Solution {
public:
    int M = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefixSum(n + 1, 0);
        vector<int> prefixCount(n + 1, 0);

        vector<long long> numPrefix;
        numPrefix.push_back(0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + digit;
            prefixCount[i + 1] = prefixCount[i];

            if (digit > 0) {
                prefixCount[i + 1]++;
                long long newNum = (numPrefix.back() * 10 + digit) % M;
                numPrefix.push_back(newNum);
            }
        }

        int totalNonZero = numPrefix.size();
        vector<long long> pow10(totalNonZero + 1, 1);

        for (int i = 1; i <= totalNonZero; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        vector<int> answer;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefixSum[r + 1] - prefixSum[l];

            int leftCount = prefixCount[l];
            int rightCount = prefixCount[r + 1];
            int len = rightCount - leftCount;

            long long x = (
                numPrefix[rightCount] -
                (numPrefix[leftCount] * pow10[len]) % M +
                M
            ) % M;

            long long ans = (x * sum) % M;
            answer.push_back(ans);
        }

        return answer;
    }
};