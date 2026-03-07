class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Min heap of available rooms
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        // Min heap of busy rooms: {endTime, room}
        priority_queue<pair<long long,int>, 
            vector<pair<long long,int>>, greater<>> busy;

        vector<long long> used(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;

            // Free rooms that have completed by start time
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busy.push({end, room});
                used[room]++;
            } else {
                auto [freeTime, room] = busy.top();
                busy.pop();
                busy.push({freeTime + duration, room});
                used[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (used[i] > used[ans]) ans = i;
        }
        return ans;
    }
};
