class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = position in word1 where word2[j...]
        // can start being matched.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Match word2 from right to left.
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // word2 cannot even be matched as a subsequence.
        // However, we are allowed ONE mismatch.
        // So this condition alone is not enough to return here.
        
        vector<int> ans;

        i = 0;
        j = 0;

        bool usedMismatch = false;

        while (i < n && j < m) {

            // Case 1: Characters match.
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Case 2: Use the one allowed mismatch.
            else if (!usedMismatch) {

                // If this is the last character, we can always
                // use the mismatch.
                if (j == m - 1) {
                    ans.push_back(i);
                    usedMismatch = true;
                    j++;
                }

                // Otherwise, make sure the remaining suffix
                // can still be matched after i.
                else if (last[j + 1] != -1 &&
                         i < last[j + 1]) {

                    ans.push_back(i);
                    usedMismatch = true;
                    j++;
                }
            }

            i++;
        }

        // We need exactly m indices.
        if (j == m)
            return ans;

        return {};
    }
};