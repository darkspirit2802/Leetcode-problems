class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        // Use long long to prevent integer overflow during summation [4]
        vector<long long> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = nums[i]; // [4]
        }

        // Stores {sum, index} for adjacent pairs, automatically sorted by sum [5]
        set<pair<long long, int>> minPairSet;
        
        // Arrays to store previous and next indices to simulate deletion [5]
        vector<int> next_idx(n), prev_idx(n);
        for(int i = 0; i < n; i++) {
            next_idx[i] = i + 1;
            prev_idx[i] = i - 1; // [5]
        }

        int bad_pairs = 0;
        // Populate the set and count initial bad pairs [6]
        for(int i = 0; i < n - 1; i++) {
            if(temp[i] > temp[i+1]) {
                bad_pairs++; // [6]
            }
            minPairSet.insert({temp[i] + temp[i+1], i}); // [6]
        }

        int ops = 0;
        // Continue operations until the array is non-decreasing (bad_pairs == 0) [6]
        while(bad_pairs > 0) {
            auto it = minPairSet.begin();
            // Extract indices of the pair with the minimum sum [7]
            int first = it->second;
            int second = next_idx[first];

            // Identify neighbors affected by the merge [7]
            int first_left = prev_idx[first];
            int second_right = next_idx[second];

            minPairSet.erase(it); // Remove the current minimum pair from the set [7]

            // If the removed pair was a bad pair (decreasing), decrement count [7]
            if(temp[first] > temp[second]) {
                bad_pairs--; 
            }

            long long new_sum = temp[first] + temp[second];

            // 1. Handle the Left Neighbor [8]
            if(first_left >= 0) {
                // Check if relationship changes from Bad to Good
                if(temp[first_left] > temp[first] && temp[first_left] <= new_sum) {
                    bad_pairs--; // [9]
                } 
                // Check if relationship changes from Good to Bad
                else if(temp[first_left] <= temp[first] && temp[first_left] > new_sum) {
                    bad_pairs++; // [9]
                }

                // Update the set: remove old relationship, insert new one [10]
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + new_sum, first_left});
            }

            // 2. Handle the Right Neighbor [8]
            if(second_right < n) {
                // Check if relationship changes from Bad to Good (based on 'second' vs 'second_right')
                if(temp[second] > temp[second_right] && new_sum <= temp[second_right]) {
                    bad_pairs--; // [8, 11]
                } 
                // Check if relationship changes from Good to Bad
                else if(temp[second] <= temp[second_right] && new_sum > temp[second_right]) {
                    bad_pairs++; // [8, 11]
                }

                // Update the set: remove old relationship, insert new one [12]
                minPairSet.erase({temp[second] + temp[second_right], second});
                // Note: The merged element sits at index 'first', so new pair starts at 'first' [12]
                minPairSet.insert({new_sum + temp[second_right], first});
                
                // Update pointers: right neighbor now points back to 'first' [12]
                prev_idx[second_right] = first;
            }

            // Final Updates for the current operation [13]
            next_idx[first] = second_right; // First now points to second_right
            temp[first] = new_sum;          // Replace first value with the sum
            ops++;                          // Increment operation count
        }

        return ops; // [13]
    }
};