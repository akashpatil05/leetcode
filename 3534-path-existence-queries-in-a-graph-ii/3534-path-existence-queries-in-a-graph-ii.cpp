class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        // 1. Sort by value, while remembering original indices
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        // pos[original index] = sorted position
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[a[i].second] = i;
        }

        // 2. Find farthest one-edge jump using two pointers
        vector<int> nxt(n);

        int r = 0;

        for (int i = 0; i < n; i++) {
            if (r < i) r = i;

            while (r + 1 < n &&
                   a[r + 1].first - a[i].first <= maxDiff) {
                r++;
            }

            nxt[i] = r;
        }

        // 3. Build binary lifting table
        int LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] =
                    up[k - 1][up[k - 1][i]];
            }
        }

        // 4. Answer queries
        vector<int> ans;

        for (auto& q : queries) {
            int L = pos[q[0]];
            int R = pos[q[1]];

            if (L > R) {
                swap(L, R);
            }

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            // Check connectivity
            int cur = L;

            for (int k = LOG - 1; k >= 0; k--) {
                cur = max(cur, up[k][cur]);
            }

            if (cur < R) {
                ans.push_back(-1);
                continue;
            }

            // Find minimum number of jumps
            cur = L;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < R) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};