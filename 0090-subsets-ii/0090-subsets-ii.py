class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(i, subset):
            if i == len(nums):
                res.append(subset.copy())
                return 

            #include ele
            subset.append(nums[i])
            dfs(i+1, subset)
            subset.pop()
            # exclude
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i+= 1
            dfs(i+1, subset)

        dfs(0, [])
        return res