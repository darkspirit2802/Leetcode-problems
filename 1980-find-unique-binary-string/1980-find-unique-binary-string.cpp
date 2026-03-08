class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;

        for(string &num : nums){
            st.insert(stoi(num,0,2));
        }
        int n = nums.size();
        string result = "";

        for(int num = 0; num<=n;num++){
            if(st.find(num)==st.end()){
                result = bitset<16>(num).to_string();
                return result.substr(16-n,n);
            }
        }

        return "";

    }
};