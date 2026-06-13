class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        for (string &word : words) {
            long long sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int r = sum % 26;

            
            res.push_back('z' - r);
        }

        return res;
    }
};