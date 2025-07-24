/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    qsort(nums, numsSize, sizeof(int), compare);
    int maxTriplets = numsSize * numsSize; 
    int** result = malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = malloc(maxTriplets * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
        int l = i + 1;
        int k = numsSize - 1;
        while (l < k) 
        {
            int sum = nums[i] + nums[l] + nums[k];
            if (sum == 0) 
            {
                int* triplet = malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[l];
                triplet[2] = nums[k];

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                //skip dupes
                while (l < k && nums[l] == nums[l + 1]) l++;
                while (l < k && nums[k] == nums[k - 1]) k--;

                l++;
                k--;
            } 
            else if (-nums[i] < nums[l] + nums[k]) 
            {
                k--;
            } else 
            {
                l++;
            }
        }
    }

    return result;
}