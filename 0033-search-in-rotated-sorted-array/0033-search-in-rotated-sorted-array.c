int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }
  return -1;
}
int search(int* nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] == target)
            return m;

       
        if (nums[l] <= nums[m]) {
            if (nums[l] <= target && target < nums[m]) {
               
                return binarySearch(nums, l, m - 1, target);
            } else {
                l = m + 1;
            }
        }
        else {
            if (nums[m] < target && target <= nums[r]) {
                return binarySearch(nums, m + 1, r, target);
            } else {
                r = m - 1;
            }
        }
    }

    return -1;
}
