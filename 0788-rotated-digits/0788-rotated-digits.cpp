class Solution {
public:
    bool isGood(int i ){
        bool changed = false;
        while(i>0){
            int digit = i%10;
            if(digit==3 ||digit==4|| digit==7) return false;
            if(digit==2 ||digit==5|| digit==6 || digit==9) changed = true;

            i/=10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }
};