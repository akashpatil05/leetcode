class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        for(int i = 0; i<k; i++){
            sum += nums[i];
            freq[nums[i]]++;
        }
        long long ans = 0;
        if(freq.size() == k){
            ans = sum;
        }
        for(int right=k; right<n; right++){
            sum -= nums[left];
            freq[nums[left]]--;
            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;
            sum+= nums[right];
            freq[nums[right]]++;
            if(freq.size() == k){
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};