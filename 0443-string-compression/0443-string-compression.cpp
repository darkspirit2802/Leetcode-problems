class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        vector<pair<char,int>> vp;

        int count = 1;

        for(int i = 1; i < n; i++) {
            char ch = chars[i-1];

            if(chars[i] == chars[i-1]) {
                count++;
            } 
            else {
                vp.push_back({ch, count});
                count = 1;
            }
        }

        // last group
        vp.push_back({chars[n-1], count});

        int index = 0;

        for(auto &it : vp) {
            chars[index++] = it.first;

            if(it.second > 1) {
                string cnt = to_string(it.second);

                for(char c : cnt) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};