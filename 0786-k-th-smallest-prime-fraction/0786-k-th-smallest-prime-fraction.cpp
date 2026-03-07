class Solution {
public:
    typedef pair<double,pair<int,int>> P;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
         int n = arr.size();
         priority_queue<P,vector<P>> pq;
         vector<int> result;
         for(int i = 0; i<n;i++){

            for(int j = i + 1 ; j < n ; j++){
                double fraction = (double)arr[i] / (double)arr[j];
                pq.push({fraction,{arr[i],arr[j]}});
                if(pq.size() > k){
                    pq.pop();
                }
            }
         }  
         int first = pq.top().second.first;
         int second = pq.top().second.second;

         result.push_back(first);
         result.push_back(second);
            
         return result;
    }
};