int findMin(int* nums, int numsSize) {
    int* l = nums;
    int* r = nums + numsSize - 1;

    while (l < r) {
        if (*(l + (r - l) / 2) > *r)
            l = l + (r - l) / 2 + 1;
        else
            r = l + (r - l) / 2;
    }

    return *l;
}
