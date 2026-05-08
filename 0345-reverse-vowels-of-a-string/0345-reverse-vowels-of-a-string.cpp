class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();

        vector<bool> vow(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                vow[i] = true;
            }
        }

        int i = 0;
        int j = n - 1;

        while (i < j) {
            while ( i<j && vow[i] != true){
                i++;
            }
            while(i<j && vow[j]!=true){
                j--;
            }
            swap(s[i],s[j]);          
            i++;
            j--;
        }
        return s;
    }
};