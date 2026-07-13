class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;

        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {

                string s = digits.substr(i, len);
                int num = stoi(s);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};