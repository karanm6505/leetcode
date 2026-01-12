/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
    int *returnArray = (int *)(malloc(2*numsSize*sizeof(int)));
    *returnSize = 2*numsSize;
    for(int i = 0; i < numsSize; i++)
    {
        returnArray[i] = nums[i];
        returnArray[i + numsSize] = nums[i];
    }
    return returnArray;
}