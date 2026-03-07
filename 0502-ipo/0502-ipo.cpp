class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;
        
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end()); // sort by capital
        priority_queue<int> pq; // max heap of profits
        
        int idx = 0;
        for(int i = 0; i < k; i++){
            // push all projects that are affordable
            while(idx < n && projects[idx].first <= w){
                pq.push(projects[idx].second);
                idx++;
            }
            
            if(pq.empty()) break; // no project affordable
            
            w += pq.top(); // pick the most profitable
            pq.pop();
        }
        
        return w;
    }
};
