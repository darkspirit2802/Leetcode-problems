class Solution {
public:
    long long sumAndMultiply(int n) {
        string digits = "";
        long long sum = 0;
        if(n==0){
            return 0;
        }
        while(n){
            int digit = n%10;
            if(digit > 0){
                digits += to_string(digit);
                sum += digit;
            }
            n = n/10;
        }
        reverse(begin(digits),end(digits));
        long long number = stoi(digits);
        long long ans = number * sum;
        return ans;
    }
};