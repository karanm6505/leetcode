int compare(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b);
}
int missingNumber(int* nums, int numsSize) 
{
    // qsort(nums, numsSize, sizeof(int), compare);
    int count[10001] = {0};
    for(int i = 0; i < numsSize; i++)
    {
        count[nums[i]] += 1;
    }
    for(int i = 0; i < 10001; i++)
    {
        if(!count[i]) return i;
    }
    return nums[numsSize-1];
}