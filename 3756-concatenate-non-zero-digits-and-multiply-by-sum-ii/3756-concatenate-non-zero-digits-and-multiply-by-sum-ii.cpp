class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;

        vector<int> pos;
        vector<int> digits;

        // Store only non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digits.push_back(s[i] - '0');
            }
        }

        int k = digits.size();

        vector<long long> prefSum(k + 1, 0);
        vector<long long> prefNum(k + 1, 0);
        vector<long long> pow10(k + 1, 1);

        for (int i = 0; i < k; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];

            prefNum[i + 1] =
                (prefNum[i] * 10 + digits[i]) % MOD;

            pow10[i + 1] =
                (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int L = lower_bound(
                pos.begin(), pos.end(), l
            ) - pos.begin();

            int R = upper_bound(
                pos.begin(), pos.end(), r
            ) - pos.begin();

            // No non-zero digit
            if (L == R) {
                ans.push_back(0);
                continue;
            }

            long long sum =
                prefSum[R] - prefSum[L];

            long long x =
                (prefNum[R]
                - prefNum[L] * pow10[R - L] % MOD
                + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};