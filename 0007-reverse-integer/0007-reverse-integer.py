class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        if x >= 0:
            res = int(s[::-1])
        else:
            res = -int(s[:0:-1]) 

        if res < -2**31 or res > 2**31 - 1:
            return 0
        return res
