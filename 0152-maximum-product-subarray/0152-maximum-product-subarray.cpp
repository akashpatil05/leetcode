class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxcount = nums[0];
        int mincount = nums[0];
        int ans = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(maxcount, mincount);
            }
            maxcount = max(nums[i], nums[i] * maxcount);
            mincount = min(nums[i], nums[i] * mincount);
            ans = max(ans, maxcount);
        }
        return ans;
    }
};