class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;

        for (string& query : queries) {

            for (string& s : dictionary) {
                int diff = 0;
                for (int i = 0; i < query.size(); i++) {
                    if (s[i] != query[i]) {
                        diff++;
                    }
                    if (diff > 2) {
                        break;
                    }
                }
                if (diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};