class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             int& nodes,
             int& degreeSum) {

        visited[node] = 1;
        nodes++;

        degreeSum += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                int nodes = 0;
                int degreeSum = 0;

                dfs(i, adj, visited, nodes, degreeSum);

                int totalEdges = degreeSum / 2;

                if (totalEdges == nodes * (nodes - 1) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};