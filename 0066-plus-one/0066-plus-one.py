class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if digits[-1] < 9:
            digits[-1] += 1
        else:
            i = len(digits) - 1
            while i >= 0 and digits[i] == 9:
                digits[i] = 0
                i -= 1
            if i >= 0:
                digits[i] += 1
            else:
                digits = [1] + digits
        return digits