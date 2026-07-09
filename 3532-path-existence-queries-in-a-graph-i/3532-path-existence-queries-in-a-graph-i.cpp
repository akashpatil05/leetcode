class Solution {
public:
    vector<bool> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<int> component(n);

        int comp = 0;
        component[0] = comp;

        for (int i = 1; i < n; i++) {

            if (nums[i] - nums[i - 1] > maxDiff) {
                comp++;
            }

            component[i] = comp;
        }

        vector<bool> ans;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (component[u] == component[v]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};