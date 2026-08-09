class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        nums.sort()

        def dfs(i, nums):

            if i == len(nums):
                res.append(nums.copy())
                return

            x = set()

            for j in range(i, len(nums)):
                if nums[j] in x:
                    continue
                
                x.add(nums[j])
                nums[i], nums[j] = nums[j], nums[i]
                dfs(i + 1, nums)
                nums[i], nums[j] = nums[j], nums[i]

        dfs(0, nums)
        return res
