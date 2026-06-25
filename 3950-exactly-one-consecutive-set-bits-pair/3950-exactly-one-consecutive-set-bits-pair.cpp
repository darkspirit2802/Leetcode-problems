class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;

        while (n > 0) {
            if ((n & 1) && ((n >> 1) & 1))
                cnt++;

            if (cnt > 1) return false;
            n >>= 1;
        }

        return cnt == 1;
    }
};