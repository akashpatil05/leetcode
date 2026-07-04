class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n + 1);

        // Build undirected graph
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[neighbor, weight] : graph[node]) {

                // Consider every edge in the component
                ans = min(ans, weight);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};