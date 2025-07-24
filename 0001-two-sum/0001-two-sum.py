class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        idx = {}
        for i, num in enumerate(nums):
            idx[num] = i
        for i, num in enumerate(nums):
            diff = target - num
            if diff in idx and idx[diff] != i:
                return[idx[diff],i]
        return []
        