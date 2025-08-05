int* merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int i = 0; int j = 0; int k = 0;
    int a = m + n;
    int *nums3 = malloc((m+n) * sizeof(int));
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
    while( j < n)
    {
        nums3[k++] = nums2[j++];
    }
    return nums3;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int* mer = malloc( (nums1Size + nums2Size) * sizeof(int));
    mer = merge(nums1,nums1Size,nums1Size,nums2,nums2Size,nums2Size);
    if((nums1Size + nums2Size)%2 == 1)
    {
        return mer[(nums1Size + nums2Size)/2];
    }
    else
    {
        printf("%d", (nums1Size + nums2Size)/2);
        int idx = (nums1Size + nums2Size)/2 + 1;
        printf("%d", idx);
        return 0.5 * (mer[(nums1Size + nums2Size)/2 - 1] +  mer[idx - 1]);
    }
}