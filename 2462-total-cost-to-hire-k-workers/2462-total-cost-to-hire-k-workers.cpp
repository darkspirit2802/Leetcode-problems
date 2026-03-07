class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int,vector<int>, greater<int>> pq1;
        priority_queue<int,vector<int>, greater<int>> pq2;

        long long cost =  0;
        long long min_pq1;
        long long min_pq2;
        int i = 0;
        int j  =  n-1;
        int hired = 0;
        while(hired < k){
            
            while(pq1.size() < candidates && i <= j){
                pq1.push(costs[i]);
                i++;
            }
           
            while(pq2.size() < candidates && i <= j){
                pq2.push(costs[j]);
                j--;
            }

            min_pq1  = pq1.size() > 0 ? pq1.top() : INT_MAX;
             min_pq2  = pq2.size() > 0 ? pq2.top() : INT_MAX;
           
             if(min_pq1 <= min_pq2){
                cost += min_pq1;
                pq1.pop();
             }
             else{
                cost += min_pq2;
                pq2.pop();
             }

            hired++;
             

        }

        return cost;
    }
};