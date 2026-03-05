class Solution {
public:
    bool isPowerOfTwo(int n) {
    int count = __builtin_popcount(n);
    if(n<=0){return false;}
    if(count == 1)
        {return true;}
        return false;
    }
};