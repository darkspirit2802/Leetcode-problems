class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;

        // Find the maximum digit range
        for (int num : nums) {
            int x = num;
            int smallest = 9;
            int largest = 0;

            while (x > 0) {
                int digit = x % 10;

                smallest = min(smallest, digit);
                largest = max(largest, digit);

                x /= 10;
            }

            int digitRange = largest - smallest;
            maxRange = max(maxRange, digitRange);
        }

        // Sum numbers having the maximum digit range
        int result = 0;

        for (int num : nums) {
            int x = num;
            int smallest = 9;
            int largest = 0;

            while (x > 0) {
                int digit = x % 10;

                smallest = min(smallest, digit);
                largest = max(largest, digit);

                x /= 10;
            }

            int digitRange = largest - smallest;

            if (digitRange == maxRange) {
                result += num;
            }
        }

        return result;
    }
};