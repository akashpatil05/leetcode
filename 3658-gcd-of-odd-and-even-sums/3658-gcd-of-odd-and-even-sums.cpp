class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;

        for (int i = 1; i <= n; i++) {
            oddSum += 2 * i - 1;
            evenSum += 2 * i;
        }

        return gcd(oddSum, evenSum);
    }
};