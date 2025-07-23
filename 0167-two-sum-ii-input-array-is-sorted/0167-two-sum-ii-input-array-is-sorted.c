/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int l = 0;
    int r = numbersSize - 1;

    while (l < r)
    {
        int sum = *(numbers + l) + *(numbers + r);

        if (sum == target)
        {
            int *returnArray = (int*)malloc(2 * sizeof(int));
            if (returnArray == NULL) {
                *returnSize = 0;
                return NULL;
            }
            returnArray[0] = l+1;
            returnArray[1] = r+1;
            *returnSize = 2;
            return returnArray;
        }
        else if (target > sum)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    *returnSize = 0;
    return NULL;
}