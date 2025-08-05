/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int i = 0; int j = 0; int k = 0;
    int *nums3 = malloc((m + n) * sizeof(int));
    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j])
        {
            nums3[k++] = nums1[i++];
        }
        else
        {
            nums3[k++] = nums2[j++];
        }
    }
    while(i < m)
    {
        nums3[k++] = nums1[i++];
    }
    while(j < n)
    {
        nums3[k++] = nums2[j++];
    }
    return nums3;
}

int* sortArray(int* nums, int numsSize, int* returnSize) 
{
    *returnSize = numsSize;

    if (numsSize <= 1) {
        int* base = malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            base[i] = nums[i];
        }
        return base;
    }

    int n = numsSize;
    int mid = n / 2;

    int* B = malloc(mid * sizeof(int));
    int* C = malloc((n - mid) * sizeof(int));

    for(int i = 0; i < mid; i++)
    {
        B[i] = nums[i];
    }
    for(int i = mid; i < n; i++)
    {
        C[i - mid] = nums[i];
    }

    int leftSize, rightSize;
    int* left = sortArray(B, mid, &leftSize);
    int* right = sortArray(C, n - mid, &rightSize);

    int* merged = merge(left, leftSize, leftSize, right, rightSize, rightSize);

    free(B);
    free(C);
    free(left);
    free(right);

    return merged;
}
