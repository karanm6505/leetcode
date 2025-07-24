int findMin(int* nums, int numsSize) 
{
    int res = nums[0];
    int l = 0, r = numsSize - 1;
    while(l <= r)
    {
        if(nums[l] < nums[r])
        {
            res = res < nums[l] ? res : nums[l];
            return res;
        }
        int m = l + (r-l)/2;
        res = res < nums[m] ? res : nums[m];
        if(nums[m] >= nums[l])
        {
            l = m+1;
        }
        else r = m-1;
    }
    return res;
}