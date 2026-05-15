class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>result(n,-1);
        for(int i = 0;i<n;i++){
            int num = nums1[i];
            bool find = false;
            for(int j = 0;j<m;j++){
                if(!find && nums2[j]==num){
                    find = true;
                }
                else if(find && nums2[j]>num){
                    result[i]=nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};