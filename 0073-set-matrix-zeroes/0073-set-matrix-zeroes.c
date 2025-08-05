void setZeroes(int** matrix, int matrixSize, int* matrixColSize) 
{
    int* arr = malloc( matrixSize * *matrixColSize * sizeof(int));
    int zeroes = 0;
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < *matrixColSize; j++)
        {

            if(matrix[i][j] == 0)
            {
                arr[zeroes++] = *matrixColSize * i + j;
            }
        }
    }
    for(int i = 0; i <zeroes; i++)
    {
        int row = arr[i] / *matrixColSize;
        int col = arr[i] % *matrixColSize;
        for(int x = 0; x < *matrixColSize; x++)
        {
            matrix[row][x] = 0;
        }
        for(int y = 0; y < matrixSize; y++)
        {
            matrix[y][col] = 0;
        }
    }
}


