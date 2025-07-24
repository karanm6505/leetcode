int search(int* nums, int numsSize, int target) 
{
    int l = 0, r = numsSize - 1; 
    while(l <= r)
    {
    int m = l + (r - l) / 2;
    if(nums[m] == target)
    {
        return m;
    }
    else if(target > nums[m])
    {
        l = m + 1;
    }
    else {r=m-1;}}
    return -1;
}