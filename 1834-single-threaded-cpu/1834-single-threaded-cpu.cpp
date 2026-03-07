class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int,3>> sorted_tasks;
        for(int i = 0; i < n ; i++){
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            sorted_tasks.push_back({start_time, processing_time,i});
        }

        sort(begin(sorted_tasks),end(sorted_tasks));
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;//min heap
        vector<int> result;
        long long curr_time  = 0;
        int idx = 0;

        while(idx < n || !pq.empty()){
            if(pq.empty() && curr_time <  sorted_tasks[idx][0]){
                curr_time =sorted_tasks[idx][0];
            }
            while(idx < n && curr_time >= sorted_tasks[idx][0]){
               pq.push({sorted_tasks[idx][1],sorted_tasks[idx][2]});
               idx++;
            }
            pair<int, int> curr_tasks = pq.top();
            pq.pop();

            curr_time += curr_tasks.first;
            result.push_back(curr_tasks.second);

        }

        return result;
    }
};