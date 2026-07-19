class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<k; i++){
            sum += nums[i];
        }
        int maxsum = sum;
        for(int right = k; right<n; right++){
            sum-=nums[left];
            left++;
            sum+=nums[right];
            maxsum = max(maxsum,sum);
        }
        return (double)maxsum/k;
    }
};