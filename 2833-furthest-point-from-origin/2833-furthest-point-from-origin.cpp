class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, k = 0;
        
        for (char c : moves) {
            if (c == 'R') r++;
            else if (c == 'L') l++;
            else k++;
        }
        
        return abs(r - l) + k;
    }
};