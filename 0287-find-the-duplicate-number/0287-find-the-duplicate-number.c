int findDuplicate(int* nums, int numsSize) 
{
    int count[100001] = {0};
    for(int i = 0; i < numsSize; i++)
    {
        count[nums[i]]+=1;
    }
    for(int i = 0; i < numsSize; i++)
    {
        if(count[nums[i]] > 1)
        return nums[i];
    }
    return nums[numsSize-1];
}