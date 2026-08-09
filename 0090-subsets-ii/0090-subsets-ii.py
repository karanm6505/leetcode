class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        curList = []
        def dfs(i):
            if i == len(nums):
                res.append(curList.copy())
                return 

            #include ele
            curList.append(nums[i])
            dfs(i+1)
            curList.pop()
            # exclude
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i+= 1
            dfs(i+1)

        dfs(0)
        return res