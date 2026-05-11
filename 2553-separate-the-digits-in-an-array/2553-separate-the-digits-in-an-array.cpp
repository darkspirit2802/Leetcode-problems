class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        for(int &num : nums){
            vector<int>temp;
            while(num > 0){
                int digit = num % 10;
                temp.push_back(digit);
                num = num/10;
            }
            reverse(begin(temp),end(temp));
            for(int &i : temp){
                result.push_back(i);
            }
        }
        return result;
    }
};