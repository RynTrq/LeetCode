class Solution {
public:
    int traversal(const vector<vector<int>>& g, vector<char>& vis, int start) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int cnt = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<char> vis(n, 0);
        vector<int> comps;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) comps.push_back(traversal(g, vis, i));
        }

        long long ans = 0, pref = 0;
        for (int sz : comps) { ans += pref * sz; pref += sz; } // O(k)
        return ans;
    }
};
