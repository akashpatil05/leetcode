class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        // Distinct XORs of pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // Form triplet XORs
        for (int px : pairXor) {
            for (int x : nums) {
                tripletXor.insert(px ^ x);
            }
        }

        return tripletXor.size();
    }
};