class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows, cols = len(matrix), len(matrix[0])

        # (rows + 1) x (cols + 1) prefix sum matrix
        self.prefixMatrix = [[0] * (cols + 1) for _ in range(rows + 1)]

        for r in range(rows):
            prefixSum = 0
            for c in range(cols):
                prefixSum += matrix[r][c]
                above = self.prefixMatrix[r][c + 1]
                self.prefixMatrix[r + 1][c + 1] = prefixSum + above

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        bottomRight = self.prefixMatrix[row2 + 1][col2 + 1]
        above = self.prefixMatrix[row1][col2 + 1]
        left = self.prefixMatrix[row2 + 1][col1]
        topLeft = self.prefixMatrix[row1][col1]

        return bottomRight - above - left + topLeft