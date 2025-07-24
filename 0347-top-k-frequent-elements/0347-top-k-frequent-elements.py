class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        #building of the frequency map
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        #creating the bucket to hold values of frequency f
        buckets = [[] for _ in range(len(nums) + 1)]

        for num, f in freq.items():
            buckets[f].append(num)

        result = []
        for freq in range(len(buckets) - 1, 0, -1):
            for num in buckets[freq]:
                result.append(num)
                if len(result) == k:
                    return result

        return result