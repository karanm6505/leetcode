bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) 
{
    if (matrixSize == 0 || *matrixColSize == 0) return 0;

    int rows = matrixSize;
    int cols = *matrixColSize;
    int l = 0, r = rows * cols - 1;

    while (l <= r) 
    {
        int m = l + (r - l) / 2;
        int mid_val = matrix[m / cols][m % cols];  

        if (mid_val == target) 
        {
            return true;
        } 
        else if (mid_val < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return false; }