

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int row = 0, l = 0, r = *matrixColSize - 1;
    for(row = 0; row < matrixSize; row++)
    {
        int l = 0, r = *matrixColSize - 1;
        int m;
        while(l <= r)
        {
            m = (l+r)/2;
            if(matrix[row][m] == target)
            {
                return true;
            }
            else if(matrix[row][m] < target)
            {
                l = m + 1;
            }
            else r = m - 1;
        }
    }
    return false;
}