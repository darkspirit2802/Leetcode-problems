class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //(n*m)Brute force
        // int n = nums1.size();
        // int m = nums2.size();
        // vector<int>result(n,-1);
        // for(int i = 0;i<n;i++){
        //     int num = nums1[i];
        //     bool find = false;
        //     for(int j = 0;j<m;j++){
        //         if(!find && nums2[j]==num){
        //             find = true;
        //         }
        //         else if(find && nums2[j]>num){
        //             result[i]=nums2[j];
        //             break;
        //         }
        //     }
        // }
        // return result;
        stack<int>st;
        unordered_map<int,int>mp;

        for(int j =nums2.size()-1;j>=0;j--){
            while(!st.empty()&& st.top() <= nums2[j]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[j]] = -1;
            }else{
                mp[nums2[j]] = st.top();
            }

            st.push(nums2[j]);
        }

        vector<int>result;
        for(int &num : nums1){
            result.push_back(mp[num]);
        }

        return result;
    }
};