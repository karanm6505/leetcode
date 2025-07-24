class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        prefix = [1] * n
        postfix = [1] * n

        for i in range(n):
            j = n - 1 - i
            if i == 0:
                prefix[i] = nums[i]
                postfix[j] = nums[j]
            else:
                prefix[i] = nums[i] * prefix[i - 1]
                postfix[j] = nums[j] * postfix[j + 1]

        print(prefix)
        print(postfix)
        result = [1]*n
        for i in range(n):
            if i == 0:
                result[i] = postfix[i+1]
            elif i == n - 1:
                result[i] = prefix[i-1]
            else:
                result[i] = prefix[i-1]*postfix[i+1]
        return result
