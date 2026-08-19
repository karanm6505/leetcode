class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int miss = 1;
        for(int n: nums)
        {
            if(n > 0 && miss == n){ miss++; }
        }
        return miss;
}
}