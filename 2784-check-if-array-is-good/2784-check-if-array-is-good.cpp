class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 1) return false; 

        vector<int> count(n + 1, 0);

        for (int x : nums) {
            if (x > n || x < 1) return false;
            count[x]++;
        }

        for (int i = 1; i < n; i++) {
            if (count[i] != 1) return false;
        }
        
        return count[n] == 2;
    }
};