class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int right = 0; right< nums.size(); right++){
            int size = right - left +1;
            sum += nums[right];
            if(size > k){
                sum -= nums[left];
                left++;
            }
            size = right - left +1;
            if(size == k){
                ans = max(ans,sum);
            }
        }
        return (double)ans/k;
    }
};