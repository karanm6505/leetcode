class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_set = set(nums)
        longest = 0
        print(num_set)
        for i in num_set:
            if i - 1 not in num_set: #to make sure that it's the starting element
                current = i
                run = 1
                while i + 1 in num_set:
                    i += 1
                    run += 1
                longest = max(longest, run)

        return longest