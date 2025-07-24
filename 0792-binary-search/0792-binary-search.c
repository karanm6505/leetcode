int search(int* nums, int numsSize, int target) 
{
    if (numsSize == 0) return -1;  

    int left = 0, right = numsSize - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;  
}
