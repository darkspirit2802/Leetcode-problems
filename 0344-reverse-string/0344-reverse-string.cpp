class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        char temp;
        for(int ch = 0;ch<n/2;ch++){
            swap(s[ch],s[n-1-ch]);
        }
    }
};