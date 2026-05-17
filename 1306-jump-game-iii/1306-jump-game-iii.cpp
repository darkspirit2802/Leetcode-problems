class Solution {
public:
    bool solve(vector<int>& arr, int i, int n, vector<bool>& vis) {
        if (i < 0 || i >= n || vis[i]) {
            return false;
        }

        if (arr[i] == 0) {
            return true;
        }

        vis[i] = true;

        return solve(arr, i + arr[i], n, vis) ||
               solve(arr, i - arr[i], n, vis);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        return solve(arr, start, n, vis);
    }
};