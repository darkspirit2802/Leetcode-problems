class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 0));

        // DFS/BFS from root = 1
        vector<int> parent(n + 1, 0);
        queue<int> q;
        q.push(1);
        parent[1] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        for (int v = 1; v <= n; v++) {
            up[0][v] = parent[v];
        }

        for (int j = 1; j < LOG; j++) {
            for (int v = 1; v <= n; v++) {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }

        // pow2[i] = 2^i mod MOD
        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &qr : queries) {
            int u = qr[0], v = qr[1];

            int w = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[w];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)pow2[dist - 1]);
            }
        }

        return ans;
    }
};