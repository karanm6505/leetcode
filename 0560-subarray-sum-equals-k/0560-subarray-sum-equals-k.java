class Solution {
    public int subarraySum(int[] nums, int k) {
        
        int res = 0, currentSum = 0;
        HashMap<Integer, Integer> prefixSum = new HashMap<>();
        prefixSum.put(0, 1);

        for(int n: nums)
        {
            currentSum += n;
            int diff = currentSum - k;
            res += prefixSum.getOrDefault(diff, 0);
            prefixSum.put(currentSum, prefixSum.getOrDefault(currentSum, 0) + 1);
        }

        return res;
    }
}