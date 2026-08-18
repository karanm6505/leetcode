class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        if(nums == null || nums.length == 0){ return 0;}
        int maxSum = nums[0], curSum = 0;

        for(int num: nums){
            if(curSum < 0){
                curSum = 0;
            }
            curSum += num;
            maxSum = Math.max(curSum, maxSum);
        }

        return maxSum;
    }
}
