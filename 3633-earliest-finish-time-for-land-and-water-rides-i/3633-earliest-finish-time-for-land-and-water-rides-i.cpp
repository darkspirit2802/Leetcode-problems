class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long landFinish =
                (long long)landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                long long waterFinish =
                    (long long)waterStartTime[j] + waterDuration[j];

                // Land -> Water
                ans = min(ans, max(landFinish, (long long)waterStartTime[j]) +
                                   (long long)waterDuration[j]);

                // Water -> Land
                ans = min(ans, max(waterFinish, (long long)landStartTime[i]) +
                                   (long long)landDuration[i]);
            }
        }

        return (int)ans;
    }
};