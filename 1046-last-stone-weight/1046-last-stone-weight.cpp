class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int i = 0 ; i<n ; i++){
            pq.push(stones[i]);
        }
        
        while(pq.size() >1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

           
            if(first!= second){
                first = first - second;
                pq.push(first);
            }
            
        }
        return pq.empty() ? 0 : pq.top();
    }
};