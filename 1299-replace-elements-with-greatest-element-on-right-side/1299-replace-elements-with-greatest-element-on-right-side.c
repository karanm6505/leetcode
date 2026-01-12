int* replaceElements(int* arr, int arrSize, int* returnSize)
{
    int *res = (int*)malloc(sizeof(int) * arrSize);
    int maxRight = -1;

    for(int i = arrSize - 1; i >= 0; i--)
    {
        res[i] = maxRight;
        if(arr[i] > maxRight)
            maxRight = arr[i];
    }

    *returnSize = arrSize;
    return res;
}
