int findMin(int* nums, int numsSize) {
    int* l = nums;
    int* r = nums + numsSize - 1;

    while (l < r) {
        int* m = l + (r - l) / 2;
        if (*m > *r)
            l = m + 1;
        else
            r = m;
    }

    return *l; 
}
