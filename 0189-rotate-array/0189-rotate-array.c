void rotate(int* nums, int numsSize, int k) 
{
    int* rot = malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        
        rot[(i + k) % numsSize] = nums[i];
    }
    for(int i = 0; i < numsSize; i++)
    {
        nums[i] = rot[i];
    }
    free(rot);
}