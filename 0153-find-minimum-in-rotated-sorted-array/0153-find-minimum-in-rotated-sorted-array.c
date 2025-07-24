int findMin(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;

    while (l < r) 
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) 
        {
            l = mid + 1;
        } 
        else 
        {
            r = mid;
        }
    }

    return nums[l];
}
