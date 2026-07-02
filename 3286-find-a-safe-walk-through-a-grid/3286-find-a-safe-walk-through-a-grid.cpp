class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<tuple<int, int, int>> q;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        best[0][0] = startHealth;
        q.push({0, 0, startHealth});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, curHealth] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int newHealth = curHealth - grid[nr][nc];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    q.push({nr, nc, newHealth});
                }
            }
        }

        return false;
    }
};