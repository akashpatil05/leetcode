class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<long long>> dp(
            mx + 1,
            vector<long long>(mx + 1, 0)
        );

        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<long long>> next = dp;

            for (int gcd1 = 0; gcd1 <= mx; gcd1++) {
                for (int gcd2 = 0; gcd2 <= mx; gcd2++) {

                    if (dp[gcd1][gcd2] == 0)
                        continue;

                    long long ways = dp[gcd1][gcd2];

                    // Add num to seq1
                    int newGcd1 = gcd(gcd1, num);

                    next[newGcd1][gcd2] =
                        (next[newGcd1][gcd2] + ways) % MOD;

                    // Add num to seq2
                    int newGcd2 = gcd(gcd2, num);

                    next[gcd1][newGcd2] =
                        (next[gcd1][newGcd2] + ways) % MOD;
                }
            }

            dp = next;
        }

        long long ans = 0;

        for (int g = 1; g <= mx; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};