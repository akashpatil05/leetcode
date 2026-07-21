class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int totalOnes = 0;
        int mx = 0;
        int prevZero = INT_MIN;

        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            int len = j - i;

            if (s[i] == '1') {
                totalOnes += len;
            } else {
                mx = max(mx, prevZero + len);
                prevZero = len;
            }

            i = j;
        }

        return totalOnes + mx;
    }
};