class Solution {
public:
    int bitwiseComplement(int n) {
        int counter = 0;
        int result = 0;
        if(n==0){
            return 1;
        }
        while(n){
            int r = n%2;
            result += (pow(2,counter) * (!r));
            counter++;
            n = n/2;
        }
        return result;
    }
};