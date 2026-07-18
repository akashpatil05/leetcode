class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left =0;
        int n = nums.size();
        for(int right =0; right<n; right++){
            if(nums[left] != nums[right]){
                left++;
                nums[left] = nums[right];
                
            }
        }
        return left+1;
    }
};