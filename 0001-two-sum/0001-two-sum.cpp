class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int,int>hash;
        for(int i = 0;i<n;i++){
            hash[nums[i]] = i;
        }
        for(int i = 0;i<n;i++){
            int second = target - nums[i];
            if(hash.find(second)!=hash.end() && hash[second] != i ){
                return {i,hash[second]};
            }
        }
        return {};
    }
};