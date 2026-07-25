class Solution(object):
    def twoSum(self, nums, target):
        mp= {}
        for i,nums in enumerate(nums):
            rem = target - nums
            if rem in mp:
                return [mp[rem],i]
            
            mp[nums] = i