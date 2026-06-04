class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int totalWaviness = 0;

        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);
            int m = s.length();

            if (m < 3) continue;

            int peak = 0;
            int valley = 0;

            for (int j = 1; j < m - 1; j++) {
                if (s[j] > s[j - 1] && s[j] > s[j + 1]) {
                    peak++;
                } 
                else if (s[j] < s[j - 1] && s[j] < s[j + 1]) {
                    valley++;
                }
            }

            totalWaviness += peak + valley;
        }

        return totalWaviness;
    }
};