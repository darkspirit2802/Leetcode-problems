class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>result(n+1,0);
        for(int i = 1;i<n+1;i++){
            result[i] = result[i-1] + gain[i-1]; 
        }
        sort(begin(result),end(result));
        return result[n];
        
    }
};