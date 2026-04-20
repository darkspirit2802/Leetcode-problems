class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer for the position of the next non-val element
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                // Move the valid element to the 'k' index
                nums[k] = nums[i];
                // Increment k to point to the next available slot
                k++;
            }
        }
        
        return k; // k is the count of elements not equal to val
    }
};