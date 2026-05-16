class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double ans = 0;
        double maxi = INT_MIN;
        while(j<n){
            ans += nums[j];
            if(j-i+1 == k){
                maxi = max(maxi,ans);
                ans -= nums[i];
                i++;
            }
            j++;
        }
        return maxi/(double)k;
    }
};